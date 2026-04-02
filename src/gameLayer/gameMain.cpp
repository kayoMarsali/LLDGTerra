#include "gameMain.h"
#include <raylib.h>
#include <print>

struct GameData {
	float posX = 100;
	float posY = 100;
} gameData;

bool initGame() {
	return true;
}

bool updateGame() {

	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	Color c = {255, 0, 200, 255};

	if (IsKeyDown(KEY_A)) { gameData.posX -= 200 * deltaTime; }
	if (IsKeyDown(KEY_D)) { gameData.posX += 200 * deltaTime; }
	if (IsKeyDown(KEY_W)) { gameData.posY -= 200 * deltaTime; }
	if (IsKeyDown(KEY_S)) { gameData.posY += 200 * deltaTime; }

	DrawRectangle(gameData.posX, gameData.posY, 50, 50, c);

	return true;
}

void closeGame() {
	std::println("I'ma closin yer game!");
}