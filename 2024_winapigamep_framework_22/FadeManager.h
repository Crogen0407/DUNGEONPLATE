#pragma once
class FadeObject;
class FadeManager
{
	DECLARE_SINGLE(FadeManager);
	~FadeManager();
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void LoadScene(std::wstring sceneName);
public:
	void FadeIn();
	void FadeOut();
private:
	std::wstring _sceneName;
	FadeObject* _fadeObject = nullptr;
	bool _isSceneFading = false;
	bool _sceneLoadComplete = false;
	float _curTime = 0.0f;
};