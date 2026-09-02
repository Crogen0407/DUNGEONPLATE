#pragma once

// 각종 include
#include<tchar.h>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<algorithm>
#include<ctime>
#define _USE_MATH_DEFINES
#include<math.h>
#include<functional>
#include<assert.h>

#include<Windows.h>
#include <wincodec.h>  

// DX
#include <d2d1.h>	
#include <dwrite.h>
#include <d2d1effects.h>
#include <d2d1helper.h> 
#include <wrl.h>
#include <DirectXMath.h>
using namespace DirectX;
using namespace Microsoft::WRL;

// My Header
#include "Define.h"
#include "Enums.h"
#include "Types.h"

// 각종 lib
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "msimg32.lib") 
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dwrite.lib")

// 각종 using
using std::vector;
using std::map;
using std::wstring;

// 각종 define
#define PI 3.14159265f
#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 1024

// 디버깅용 콘솔창
#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
#endif
#include<iostream>
using std::cout;
using std::endl;