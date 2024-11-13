#pragma once
class Scene;
class SceneManager
{
	DECLARE_SINGLE(SceneManager);
public:
	void Init(); // start
	void Update();
	void Render(HDC _hdc);
public:
	void RegisterScene(const wstring& _sceneName, 
					std::shared_ptr<Scene> _scene);
	void LoadScene(const wstring& _sceneName);
public:
	const std::shared_ptr<Scene>& GetCurrentScene() const
	{
		return m_pCurrentScene;
	}
private:
	// 씬들을 map으로 관리
	map<wstring, std::shared_ptr<Scene>> m_mapScenes;
	//Scene* m_pCurrentScene;
	// 현재 씬
	std::shared_ptr<Scene> m_pCurrentScene;
};

