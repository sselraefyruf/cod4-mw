#pragma once

#include "../Imgui/imgui.h"
#include "../Imgui/imgui_internal.h"
#include "../Imgui/imgui_impl_dx9.h"
#include "../Imgui/imgui_impl_win32.h"

namespace settingsXD {
	inline bool name_esp = false, line_esp = false, box_esp = false;
	inline ImVec4 BoxESP2D_Color = { 255.0f, 255.0f, 255.0f, 255.0f },Snaplines_Color = { 255.0f,255.0f,255.0f,255.0f }, Namesp_color = { 255.0f,255.0f,255.0f,255.0f };
}