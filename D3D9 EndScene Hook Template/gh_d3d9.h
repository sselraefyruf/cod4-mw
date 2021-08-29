#include "stdafx.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "mem.h"

#ifdef _WIN64
#define GWL_WNDPROC GWLP_WNDPROC
#endif

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(APIENTRY* tEndScene)(LPDIRECT3DDEVICE9 pDevice);

static HWND d3dwindow;

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam);

HWND GetProcessWindow();

bool GetD3D9Device(void** pTable, size_t Size);

void DrawFilledRect(int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* dev);