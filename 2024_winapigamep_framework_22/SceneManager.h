#pragma once
class Scene;
class Object;
class SceneManager
{
	DECLARE_SINGLE(SceneManager);
public:
	void Init(); 
	void Update();
	void Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget);
public:
	void RegisterScene(const wstring& sceneName, 
					std::shared_ptr<Scene> scene);
	void LoadScene(const wstring& sceneName);
public:
	const std::shared_ptr<Scene>& GetCurrentScene() const
	{
		return _currentScene;
	}
	Object* FindObject(std::wstring name, LAYER layer);
private:
	// 씬들을 map으로 관리
	map<wstring, std::shared_ptr<Scene>> _scenes;

	// 현재 씬
	std::shared_ptr<Scene> _currentScene;
};

