#include <iostream>
#include <print>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

#include "../gameLayer/gameMain.h"

int main() {

#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE)
#endif

	InitWindow(1920, 1080, "LLGD Terra");
	SetExitKey(KEY_NULL);
	SetTargetFPS(144);

	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 1.5;


	if (!initGame()) {
		goto shutdown;
	}

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		if (!updateGame()) {
			CloseWindow();
		}

#pragma region imgui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
		ImGui::PopStyleColor(2);



		rlImGuiEnd();
#pragma endregion

		EndDrawing();
	}
	shutdown:
	CloseWindow();

	closeGame();

	rlImGuiShutdown();
	return 0;
}