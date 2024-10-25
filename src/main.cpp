#include "raylib.h"
#include <iostream>

#pragma region imgui
#include "imgui.h"
#include "rlImGui.h"
#include "imguiThemes.h"
#pragma endregion

#include <Header.h>

int main(void)
{

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "Solar System");
    SetTargetFPS(60);
#pragma region imgui
	rlImGuiSetup(true);

	//you can use whatever imgui theme you like!
	imguiThemes::yellow();


	ImGuiIO &io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.FontGlobalScale = 1;

	ImGuiStyle &style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.Colors[ImGuiCol_WindowBg].w = 0.5f;
	}

#pragma endregion

	//Orbit Calculations
    float angle = 0.0f;
	float speed = 0.001f;
	Sun planetsun;
	Planets planetInfo;

	init(planetsun);
    Camera2D camera = {0};
    camera.target = (Vector2){0, 0}; // Camera target
    camera.offset = (Vector2){(float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f}; // Camera offset
    camera.rotation = 0.0f; // Camera rotation
    camera.zoom = 1.0f; // Camera zoom level


	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_D)) camera.target.x += 5.0f; // Move camera right
        if (IsKeyDown(KEY_A)) camera.target.x -= 5.0f; // Move camera left
        if (IsKeyDown(KEY_W)) camera.target.y -= 5.0f; // Move camera up
        if (IsKeyDown(KEY_S)) camera.target.y += 5.0f; // Move camera down
        if (IsKeyDown(KEY_Z)) camera.zoom += 0.01f; // Zoom in
        if (IsKeyDown(KEY_X)) camera.zoom -= 0.01f; // Zoom out
		BeginDrawing();
		BeginMode2D(camera);
		ClearBackground(BLACK);
		
        SolarSystemLogic(planetsun);
        DrawFPS(camera.target.x + 10, camera.target.y + 10);
		EndMode2D();
		EndDrawing();
	}


#pragma region imgui
	rlImGuiShutdown();
#pragma endregion



	CloseWindow();

	return 0;
}