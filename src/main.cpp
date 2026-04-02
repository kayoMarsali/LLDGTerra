#include <iostream>
#include <print>
#include <raylib.h>

int main() {

	InitWindow(1280, 720, "LLGD Terra");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}


	CloseWindow();
	return 0;
}