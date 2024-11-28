#pragma once
class Stage;
class StageManager
{
	DECLARE_SINGLE(StageManager);
public:
	void Init();
	void Update();
	void Render(HDC _hdc);
public:
	void RegisterStage(const wstring& _stageName,
		std::shared_ptr<Stage> _stage);
	void LoadStage(const wstring& _stageName);
private:
	map<wstring, std::shared_ptr<Stage>> m_mapStages;
	std::shared_ptr<Stage> m_pCurrentStage;
};