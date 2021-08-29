#include "cheat.h"
#include <iostream>


void visualStuffs::name_ESP() {

	ImDrawList* drawlist = ImGui::GetBackgroundDrawList();

	for (int i = 0; i < 16; ++i) {


		c_entity* Entity = reinterpret_cast<c_entity*>((0x84F2D8 + 0x1DC) + (i * 0x1DC));
		if (!Entity)
			continue;

		client_info* clientinfoEntity = reinterpret_cast<client_info*>(0x839270 + i * 0x4CC);
		if (!clientinfoEntity)
			continue;

		Vector3 origin = Entity->origin;
		if (origin.x == 0 && origin.y == 0 && origin.z == 0)
			continue;

		Vector2 Screen;
		if (WorldToScreen(origin, Screen)) {
			drawlist->AddText(ImVec2(Screen.x - ImGui::CalcTextSize(clientinfoEntity->nameXD).x / 2, Screen.y), ImGui::ColorConvertFloat4ToU32(settingsXD::Namesp_color), clientinfoEntity->nameXD);
		} 
	}

}

void visualStuffs::drawLine_ESP() {

	ImDrawList* drawlist = ImGui::GetBackgroundDrawList();

	for (int i = 0; i < 16; ++i) {
		c_entity* Entity = reinterpret_cast<c_entity*>((0x84F2D8 + 0x1DC) + (i * 0x1DC));
		if (!Entity)
			continue;

		Vector3 origin = Entity->origin;
		if (origin.x == 0 && origin.y == 0 && origin.z == 0)
			continue;

		Vector2 Screen;
		if (WorldToScreen(origin,Screen)) {
			drawlist->AddLine(ImVec2(Screen.x, Screen.y), ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y), ImGui::ColorConvertFloat4ToU32(settingsXD::Snaplines_Color));
		}

	}

}

void visualStuffs::_2DBox_ESP() {

	ImDrawList* drawlist = ImGui::GetBackgroundDrawList();

	for (int i = 0; i < 16; ++i) {
		c_entity* Entity = reinterpret_cast<c_entity*>((0x84F2D8 + 0x1DC) + (i * 0x1DC));
		if (!Entity)
			continue;

		Vector3 headPos = Entity->origin;
		headPos.z += 60.0f;

		Vector3 origin = Entity->origin;
		if (origin.x == 0 && origin.y == 0 && origin.z == 0)
			continue;

		Vector2 Screen, Screen2;
		if (WorldToScreen(origin, Screen) && WorldToScreen(headPos, Screen2)) {
			float head_x = Screen2.y - Screen.y;
			float width = head_x / 2;
			float center = width / -2;
			drawlist->AddRect(ImVec2(Screen.x + center, Screen.y), ImVec2(Screen.x - center, Screen2.y), ImGui::ColorConvertFloat4ToU32(settingsXD::BoxESP2D_Color));
		}
	}

}