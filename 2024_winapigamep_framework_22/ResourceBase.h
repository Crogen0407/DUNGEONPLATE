#pragma once
class ResourceBase
{
public:
	ResourceBase() = default;
	//ResourceBase() {}
	virtual ~ResourceBase() = default;
public:
	void SetKey(const wstring& _key) { m_strKey = _key; }
	void SetPath(const wstring& _path) { m_strRelativePath = _path; }
	const wstring& GetKey()  const { return m_strKey; }
	const wstring& GetPath() const  { return m_strRelativePath; }	
private:
	wstring m_strRelativePath; // °æ·Î
	wstring m_strKey; // Å°
};

