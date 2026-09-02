#include "pch.h"
#include "ResourceManager.h"
#include "Core.h"
#include "Texture.h"
#include "FontCollectionLoader.h"

void ResourceManager::Init()
{
	::CoCreateInstance(
		CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&_wicFactory)
	);

	::DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED, 
		__uuidof(IDWriteFactory), 
		&_writeFactory
	);

	::GetCurrentDirectory(255, m_resourcePath);
	wcscat_s(m_resourcePath, 255, L"\\Resource\\");

	ma_result result = ma_engine_init(nullptr, &m_soundEngine);
	if (result != MA_SUCCESS)
	{
		// 초기화 실패 처리 (로그 등)
		m_bEngineInitialized = false;
		return;
	}
	m_bEngineInitialized = true;

	for (int i = 0; i < (int)SOUND_CHANNEL::END; ++i)
	{
		m_fChannelVolume[i] = 1.0f;
		m_pPlayingSound[i] = nullptr;
		m_bChannelPause[i] = false;
	}
}

Texture* ResourceManager::TextureLoad(const wstring& _key, const wstring& _path)
{
    Texture* pTex = TextureFind(_key);
    if (nullptr != pTex)
        return pTex;

    // 전체 경로 조합
    wstring texpath = m_resourcePath;
    texpath += _path;

    if (!_wicFactory)
    {
        OutputDebugStringA("ResourceManager::TextureLoad - _wicFactory is NULL\n");
        return nullptr;
    }

    ComPtr<IWICBitmapDecoder> decoder;
    HRESULT hr = _wicFactory->CreateDecoderFromFilename(
        texpath.c_str(), // 안전한 c_str() 사용
        nullptr,
        GENERIC_READ,
        WICDecodeMetadataCacheOnLoad,
        &decoder
    );

    if (FAILED(hr) || !decoder)
    {
        OutputDebugStringA("ResourceManager::TextureLoad - CreateDecoderFromFilename failed\n");
        return nullptr;
    }

    // 첫 번째 프레임 가져오기
    ComPtr<IWICBitmapFrameDecode> frame;
    if (FAILED(decoder->GetFrame(0, &frame)) || !frame)
    {
        OutputDebugStringA("ResourceManager::TextureLoad - GetFrame failed\n");
        return nullptr;
    }

    // 포맷 변환기 생성
    ComPtr<IWICFormatConverter> converter;
    if (FAILED(_wicFactory->CreateFormatConverter(&converter)) || !converter)
    {
        OutputDebugStringA("ResourceManager::TextureLoad - CreateFormatConverter failed\n");
        return nullptr;
    }

    // 픽셀 포맷을 Direct2D 호환 포맷으로 변환
    if (FAILED(converter->Initialize(
        frame.Get(),
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        nullptr,
        0.0,
        WICBitmapPaletteTypeCustom)))
    {
        OutputDebugStringA("ResourceManager::TextureLoad - converter->Initialize failed\n");
        return nullptr;
    }

    // Direct2D 비트맵으로 변환
    ComPtr<ID2D1Bitmap> bitmap;
    if (FAILED(GET_SINGLE(Core)->GetRenderTarget()->CreateBitmapFromWicBitmap(
        converter.Get(),
        nullptr,
        &bitmap)))
    {
        OutputDebugStringA("ResourceManager::TextureLoad - CreateBitmapFromWicBitmap failed\n");
        return nullptr;
    }

    pTex = new Texture;
    pTex->SetBitmap(bitmap);
    pTex->SetKey(_key);
    pTex->SetPath(texpath);
    m_mapTextures.insert({_key,pTex});
    return pTex;
}

Texture* ResourceManager::TextureFind(const wstring& _key)
{
    auto iter = m_mapTextures.find(_key);
    if (iter != m_mapTextures.end())
        return iter->second;
    return nullptr;
}

void ResourceManager::Release()
{
    map<wstring, Texture*>::iterator iter;
    for (iter = m_mapTextures.begin(); iter != m_mapTextures.end(); ++iter)
        delete iter->second;
    m_mapTextures.clear();

    // SOUND
    for (auto& pair : m_mapSounds)
    {
        if (pair.second->bInitialized)
            ma_sound_uninit(&pair.second->sound);
        delete pair.second;
    }
    m_mapSounds.clear();
    m_mapKeyToChannel.clear();

    if (m_bEngineInitialized)
    {
        ma_engine_uninit(&m_soundEngine);
        m_bEngineInitialized = false;
    }
}

void ResourceManager::LoadSound(const wstring& _key, const wstring& _path, bool _isLoop)
{
    LoadSound(_key, _path, SOUND_CHANNEL::BGM);
    tSoundInfo* pInfo = FindSound(_key);
    if (pInfo)
        pInfo->isLoop = _isLoop;
}

// 채널을 명시적으로 지정하는 버전
void ResourceManager::LoadSound(const wstring& _key, const wstring& _path, SOUND_CHANNEL sound_channel)
{
    if (!m_bEngineInitialized)
        return;

    if (FindSound(_key))
        return;

    // 전체 경로 결합
    wstring fullPath = m_resourcePath;
    fullPath += _path;

    int size = WideCharToMultiByte(CP_UTF8, 0, fullPath.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string utf8Path(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, fullPath.c_str(), -1, utf8Path.data(), size, nullptr, nullptr);

    tSoundInfo* pInfo = new tSoundInfo();

    ma_uint32 flags = MA_SOUND_FLAG_DECODE;
    if (sound_channel == SOUND_CHANNEL::BGM)
        flags = MA_SOUND_FLAG_STREAM;

    ma_result result = ma_sound_init_from_file(
        &m_soundEngine, utf8Path.c_str(), flags, nullptr, nullptr, &pInfo->sound);

    if (result != MA_SUCCESS)
    {
        OutputDebugStringA("LoadSound: ma_sound_init_from_file failed for ");
        OutputDebugStringA(utf8Path.c_str());
        OutputDebugStringA("\n");
        delete pInfo;
        return;
    }

    pInfo->bInitialized = true;
    pInfo->isLoop = false;

    m_mapSounds[_key] = pInfo;
    m_mapKeyToChannel[_key] = sound_channel;
}

void ResourceManager::Play(const wstring& _key)
{
	tSoundInfo* pInfo = FindSound(_key);
	if (!pInfo || !pInfo->bInitialized)
		return;

	auto it = m_mapKeyToChannel.find(_key);
	if (it == m_mapKeyToChannel.end())
		return;

	SOUND_CHANNEL channel = it->second;
	UINT idx = (UINT)channel;

	// 같은 채널에서 재생중이던 사운드 정지
	if (m_pPlayingSound[idx] && m_pPlayingSound[idx] != pInfo)
	{
		ma_sound_stop(&m_pPlayingSound[idx]->sound);
		ma_sound_seek_to_pcm_frame(&m_pPlayingSound[idx]->sound, 0);
	}

	ma_sound_set_looping(&pInfo->sound, pInfo->isLoop ? MA_TRUE : MA_FALSE);
	ma_sound_set_volume(&pInfo->sound, m_fChannelVolume[idx]);
	ma_sound_seek_to_pcm_frame(&pInfo->sound, 0);
	ma_sound_start(&pInfo->sound);

	m_pPlayingSound[idx] = pInfo;
	m_bChannelPause[idx] = false;
}

void ResourceManager::Stop(SOUND_CHANNEL _channel)
{
	UINT idx = (UINT)_channel;
	if (m_pPlayingSound[idx])
	{
		ma_sound_stop(&m_pPlayingSound[idx]->sound);
		ma_sound_seek_to_pcm_frame(&m_pPlayingSound[idx]->sound, 0);
		m_pPlayingSound[idx] = nullptr;
	}
}

void ResourceManager::Volume(SOUND_CHANNEL _channel, float _vol)
{
	UINT idx = (UINT)_channel;
	m_fChannelVolume[idx] = _vol;

	if (m_pPlayingSound[idx])
		ma_sound_set_volume(&m_pPlayingSound[idx]->sound, _vol);
}

void ResourceManager::Pause(SOUND_CHANNEL _channel, bool _ispause)
{
	UINT idx = (UINT)_channel;
	m_bChannelPause[idx] = _ispause;

	if (!m_pPlayingSound[idx])
		return;

	if (_ispause)
		ma_sound_stop(&m_pPlayingSound[idx]->sound); // 일시정지 (위치 유지)
	else
		ma_sound_start(&m_pPlayingSound[idx]->sound); // 재개
}

tSoundInfo* ResourceManager::FindSound(const wstring& _key)
{
	auto it = m_mapSounds.find(_key);
	if (it == m_mapSounds.end())
		return nullptr;
	return it->second;
}

bool ResourceManager::LoadFont(const wstring& _key, const wstring& _path)
{
    if (!m_bFontLoaderRegistered)
    {
        _fontCollectionLoader = new FontCollectionLoader();
        HRESULT hr = _writeFactory->RegisterFontCollectionLoader(_fontCollectionLoader.Get());
        if (FAILED(hr)) return false;
        m_bFontLoaderRegistered = true;
    }

    ComPtr<IDWriteFontFile> fontFile;
    HRESULT hr = _writeFactory->CreateFontFileReference(_path.c_str(), nullptr, &fontFile);
    if (FAILED(hr)) return false;

    // 유효한 폰트 파일인지 검증
    BOOL isSupported = FALSE;
    DWRITE_FONT_FILE_TYPE fileType;
    DWRITE_FONT_FACE_TYPE faceType;
    UINT32 numFaces = 0;
    fontFile->Analyze(&isSupported, &fileType, &faceType, &numFaces);
    if (!isSupported) return false;

    m_vecFontFiles.push_back(fontFile);

    std::vector<ComPtr<IDWriteFontFile>>* pFiles = &m_vecFontFiles;
    hr = _writeFactory->CreateCustomFontCollection(
        _fontCollectionLoader.Get(),
        &pFiles,
        sizeof(pFiles),
        &_fontCollection
    );

    if (FAILED(hr)) return false;

    std::wcout << L"Successfully loaded font : 0x" << std::hex << hr << std::endl;
    return true;
}