#include "raylib.h"
#include "unit.h"

int main() {
    const int monitorWidth = GetMonitorWidth(0);
    const int monitorHeight = GetMonitorHeight(0);

    SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_WINDOW_RESIZABLE);
    InitWindow(monitorWidth, monitorHeight, "Hello Raylib");

    SetTargetFPS(60);

    Warrior player1("./assets/warrior/Warrior_Idle.png", {100,100}, 8, 10);
    Warrior player2("./assets/warrior/Warrior_Attack1.png", {300,100}, 4, 10);
    Warrior player3("./assets/warrior/Warrior_Attack2.png", {400,100}, 4, 10);
    Warrior player4("./assets/warrior/Warrior_Guard.png", {500,100}, 6, 10);
    Warrior player5("./assets/warrior/Warrior_Run.png", {600,100}, 6, 10);



    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        player1.Draw(); 
        player1.Update(); 
        player2.Draw(); 
        player2.Update(); 
        player3.Draw(); 
        player3.Update(); 
        player4.Draw(); 
        player4.Update(); 
        player5.Draw(); 
        player5.Update(); 
        EndDrawing();
    }
    player1.Unload();
    player2.Unload();
    player3.Unload();
    player4.Unload();
    player5.Unload();
    CloseWindow();

    return 0;
}
