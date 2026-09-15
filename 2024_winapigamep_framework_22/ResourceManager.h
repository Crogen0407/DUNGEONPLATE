#pragma once
#include "miniaudio.h"
#include "IManager.h"
class Texture;

enum class SOUND_CHANNEL // 사운드마다 채널
{
    BGM, EFFECT0, EFFECT1, EFFECT2, EFFECT3, END
};

struct tSoundInfo
{
    ma_sound sound;             // 실제 사운드 리소스
    bool isLoop = false;        // 루프 여부
    bool bInitialized = false;  // ma_sound_init 성공 여부
};

class ResourceManager : public IManager
{
public:
    void Init() override;
    const wchar_t* GetResPath() const { return m_resourcePath; }

public:
    Texture* TextureLoad(const wstring& _key, const wstring& _path);
    Texture* TextureFind(const wstring& _key);
    void Release() override;

public:
    void LoadSound(const wstring& _key, const wstring& _path, bool _isLoop);
    void LoadSound(const wstring& _key, const wstring& _path, SOUND_CHANNEL sound_channel);
    void Play(const wstring& _key);
    void Stop(SOUND_CHANNEL _channel);
    void Volume(SOUND_CHANNEL _channel, float _vol);
    void Pause(SOUND_CHANNEL _channel, bool _ispause);

public:
    const ComPtr<IDWriteFactory> GetWriteFactory() { return _writeFactory; }

private:
    tSoundInfo* FindSound(const wstring& _key);

private:
    wchar_t m_resourcePath[255] = {};
    map<wstring, Texture*> m_mapTextures;

    // ---- Sound ----
    map<wstring, tSoundInfo*> m_mapSounds;                 // 로드된 전체 사운드
    map<wstring, SOUND_CHANNEL> m_mapKeyToChannel;          // key -> 채널 매핑
    tSoundInfo* m_pPlayingSound[(UINT)SOUND_CHANNEL::END] = {}; // 채널별 현재 재생중 사운드
    float m_fChannelVolume[(UINT)SOUND_CHANNEL::END];       // 채널별 볼륨 (기본 1.0f)
    bool  m_bChannelPause[(UINT)SOUND_CHANNEL::END] = {};   // 채널별 일시정지 상태

    ma_engine m_soundEngine;   // miniaudio 엔진 (FMOD::System 대체)
    bool m_bEngineInitialized = false;

public:
    bool LoadFont(const wstring& _key, const wstring& _path); // ttf 파일 등록
    const ComPtr<IDWriteFontCollection>& GetFontCollection() { return _fontCollection; }

private:
    ComPtr<IDWriteFontCollectionLoader> _fontCollectionLoader;
    std::vector<ComPtr<IDWriteFontFile>> m_vecFontFiles; // 로드한 폰트 파일들 (컬렉션 key로 사용됨)
    bool m_bFontLoaderRegistered = false;

public:
    IWICImagingFactory* _wicFactory = nullptr;
    ComPtr<IDWriteFactory> _writeFactory = nullptr;
    ComPtr<IWICFormatConverter> _converter = nullptr;
    ComPtr<IDWriteFontCollection> _fontCollection = nullptr;
};