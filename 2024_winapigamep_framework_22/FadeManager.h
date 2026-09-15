#pragma once
#include "IManager.h"
class FadeObject;
class FadeManager : public IManager
{
	~FadeManager();
public:
	void Init() override;
	void Update() override;
	void Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget) override;
	void LoadScene(std::wstring sceneName);
public:
	void FadeIn();
	void FadeOut();
	const bool IsSceneFading() const { return _isSceneFading; }

private:
	std::wstring _sceneName;
	FadeObject* _fadeObject = nullptr;
	bool _isSceneFading = false;
	bool _sceneLoadComplete = false;
	float _curTime = 0.0f;
};