#pragma once
#include <dwrite.h>
#include <vector>
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

class FontFileEnumerator : public IDWriteFontFileEnumerator
{
public:
    FontFileEnumerator(IDWriteFactory* factory, const std::vector<ComPtr<IDWriteFontFile>>& files)
        : _factory(factory), _files(files), _index(-1) {
    }

    IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv) override
    {
        if (riid == __uuidof(IDWriteFontFileEnumerator) || riid == __uuidof(IUnknown))
        {
            *ppv = this;
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }
    IFACEMETHODIMP_(ULONG) AddRef() override { return InterlockedIncrement(&_ref); }
    IFACEMETHODIMP_(ULONG) Release() override
    {
        ULONG r = InterlockedDecrement(&_ref);
        if (r == 0) delete this;
        return r;
    }

    IFACEMETHODIMP MoveNext(BOOL* hasCurrentFile) override
    {
        _index++;
        *hasCurrentFile = (_index < (int)_files.size()) ? TRUE : FALSE;
        return S_OK;
    }
    IFACEMETHODIMP GetCurrentFontFile(IDWriteFontFile** fontFile) override
    {
        if (_index < 0 || _index >= (int)_files.size())
        {
            *fontFile = nullptr;
            return E_FAIL;
        }
        *fontFile = _files[_index].Get();
        (*fontFile)->AddRef();
        return S_OK;
    }

private:
    ULONG _ref = 1;
    IDWriteFactory* _factory;
    std::vector<ComPtr<IDWriteFontFile>> _files;
    int _index;
};

class FontCollectionLoader : public IDWriteFontCollectionLoader
{
public:
    IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv) override
    {
        if (riid == __uuidof(IDWriteFontCollectionLoader) || riid == __uuidof(IUnknown))
        {
            *ppv = this;
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }
    IFACEMETHODIMP_(ULONG) AddRef() override { return InterlockedIncrement(&_ref); }
    IFACEMETHODIMP_(ULONG) Release() override
    {
        ULONG r = InterlockedDecrement(&_ref);
        if (r == 0) delete this;
        return r;
    }

    IFACEMETHODIMP CreateEnumeratorFromKey(
        IDWriteFactory* factory,
        const void* collectionKey,
        UINT32 collectionKeySize,
        IDWriteFontFileEnumerator** fontFileEnumerator) override
    {
        // collectionKey로 'std::vector<ComPtr<IDWriteFontFile>>*'의 포인터 값을 전달받음
        if (collectionKey == nullptr || collectionKeySize != sizeof(std::vector<ComPtr<IDWriteFontFile>>*))
            return E_FAIL;

        auto pFilesPtr = *reinterpret_cast<const std::vector<ComPtr<IDWriteFontFile>>* const*>(collectionKey);
        if (!pFilesPtr)
            return E_FAIL;

        *fontFileEnumerator = new FontFileEnumerator(factory, *pFilesPtr);
        return S_OK;
    }

private:
    ULONG _ref = 1;
};