#include <iostream>
#include <print>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

int main() {

	InitWindow(1920, 1080, "LLGD Terra");

	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 1.5;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);



		#pragma region imgui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
		ImGui::PopStyleColor(2);



		rlImGuiEnd();
		#pragma endregion imgui

		EndDrawing();
	}

	rlImGuiShutdown();

	CloseWindow();
	return 0;
}