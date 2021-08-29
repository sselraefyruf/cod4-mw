#include "stdafx.h"
#include <windows.h>
#include "gh_d3d9.h"
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx9.h"
#include "Imgui/imgui_impl_win32.h"

#include "utils/cheat.h"
#include "utils/Settings.h"

HMODULE Instance = nullptr;
bool bInit = false;
tEndScene oEndScene = nullptr;
WNDPROC oWndProc = nullptr;
LPDIRECT3DDEVICE9 pD3DDevice = nullptr;
void* d3d9Device[119];


void Unload()
{
	TrampHook((char*)d3d9Device[42], (char*)oEndScene, 7);
	SetWindowLongPtr(d3dwindow, GWL_WNDPROC, (LONG_PTR)oWndProc);
	FreeLibrary(Instance);
}

bool bShow = false;

visualStuffs XD;
HRESULT APIENTRY hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (bInit == false)
	{
		pD3DDevice = pDevice;
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
		ImGui_ImplWin32_Init(d3dwindow);
		ImGui_ImplDX9_Init(pDevice);
		bInit = true;
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImDrawList* drawlist = ImGui::GetBackgroundDrawList();

	if (GetAsyncKeyState(VK_INSERT) & 1)
		bShow = !bShow;

	if (GetAsyncKeyState(VK_END) & 1)
		Unload();

	if (bShow)
		ImGui::GetIO().MouseDrawCursor = 1;
	else
		ImGui::GetIO().MouseDrawCursor = 0;

	if (bShow)
	{
		ImGui::Begin("ImGui Window", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings || ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Checkbox("Name",&settingsXD::name_esp);
		ImGui::ColorEdit4("Name Color", (float*)&settingsXD::Namesp_color, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
		ImGui::Checkbox("Line",&settingsXD::line_esp);
		ImGui::ColorEdit4("Line Color", (float*)&settingsXD::Snaplines_Color, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
		ImGui::Checkbox("2D Box", &settingsXD::box_esp);
		ImGui::ColorEdit4("2D Box Color", (float*)&settingsXD::BoxESP2D_Color, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
		ImGui::End();
	}
	if (settingsXD::name_esp) {
		XD.name_ESP();
	}
	if (settingsXD::line_esp) {
		XD.drawLine_ESP();
	}
	if (settingsXD::box_esp) {
		XD._2DBox_ESP();
	}

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return oEndScene(pDevice);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

DWORD WINAPI Init(HMODULE hModule)
{
	if (GetD3D9Device(d3d9Device, sizeof(d3d9Device)))
	{
		oEndScene = (tEndScene)TrampHook((char*)d3d9Device[42], (char*)hkEndScene, 7);
		do
			d3dwindow = GetProcessWindow();
		while (d3dwindow == NULL);
		oWndProc = (WNDPROC)SetWindowLongPtr(d3dwindow, GWL_WNDPROC, (LONG_PTR)WndProc);
	}
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		Instance = hModule;
		DisableThreadLibraryCalls(hModule);
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, nullptr));
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}