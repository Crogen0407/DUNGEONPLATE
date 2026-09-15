#pragma once
#include <typeindex>

class IManager;
class Managers
{
    DECLARE_SINGLE(Managers);
public:
    void Init();
    void Update();
	void Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget);
    void Release();

private:
	template<typename T>
	T* Add()
	{
		T* manager = new T;
		_managerVec.push_back(manager);
		return manager;
	}
public:
    template<typename T>
    T* Get()
    {
        std::type_index key = typeid(T);
        if (nullptr == _managerMap[key])
        {
            T* targetManager = nullptr;
            for (IManager* manager : _managerVec)
            {
                targetManager = dynamic_cast<T*>(manager);
                if (targetManager) break;
            }
            _managerMap[key] = targetManager;
            return targetManager;
        }
        return static_cast<T*>(_managerMap[key]);
    }
    vector<IManager*> _managerVec;
	map<std::type_index, IManager*> _managerMap;
};

