#pragma once
class Stage;
class StageManager
{
	DECLARE_SINGLE(StageManager);
public:
	static StageManager* GetInstance()
	{
		static StageManager instance;
		return &instance;
	}
public:
	void Init();
	void Update();
	void Render(HDC _hdc);
public:
	void RegisterStage(const wstring& _stageName,
		std::shared_ptr<Stage> _stage);
	void LoadStage(const wstring& _stageName);
	void NextStage();
public:
	void SetClear(bool isClear) { m_isClear = isClear; }
	bool IsClear() const { return m_isClear; }

	//std::shared_ptr<Stage> GetCurrentStage() { return m_pCurrentStage; }
private:
	map<wstring, std::shared_ptr<Stage>> m_mapStages;
	std::shared_ptr<Stage> m_pCurrentStage;
	bool m_isClear = false;
};