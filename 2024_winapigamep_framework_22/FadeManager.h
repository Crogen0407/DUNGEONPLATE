#pragma once
class FadeObject;
class FadeManager
{
	DECLARE_SINGLE(FadeManager);
	~FadeManager();
public:
	void Init();
	void Update();
	void Render(ComPtr<ID2D1RenderTarget> renderTarget);
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