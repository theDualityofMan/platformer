#include "raylib.h"
#include "unit.h"
#include "warrior.h"

int main() {
    const int monitorWidth = GetMonitorWidth(0);
    const int monitorHeight = GetMonitorHeight(0);

    SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_WINDOW_RESIZABLE);
    InitWindow(monitorWidth, monitorHeight, "Hello Raylib");

    SetTargetFPS(60);


    Warrior warrior1({100, 100});

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        if(IsKeyDown(KEY_RIGHT)) {
            warrior1.Run(3, 0, "right", true);
        }
        else if(IsKeyDown(KEY_LEFT)) {
            warrior1.Run(3, 0, "left", true);
        }
        else if(IsKeyDown(KEY_UP)) {
            warrior1.Attack();
        }
        else if(IsKeyDown(KEY_DOWN)) {
            warrior1.Guard();
        }
        else{
            warrior1.Idle();
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
