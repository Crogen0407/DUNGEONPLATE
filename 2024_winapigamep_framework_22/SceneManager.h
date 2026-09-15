#pragma once
#include "IManager.h"
class Scene;
class Object;
class SceneManager : public IManager
{
public:
	void Init() override; 
	void Update() override;
	void Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget) override;
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

