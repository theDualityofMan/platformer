#include "raylib.h"
#include "unit.h"
#include "warrior.h"
#include "blocks.h"

int main() {
    const int monitorWidth = GetMonitorWidth(0);
    const int monitorHeight = GetMonitorHeight(0);

    SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_WINDOW_RESIZABLE);
    InitWindow(monitorWidth, monitorHeight, "Hello Raylib");

    SetTargetFPS(60);


    Warrior warrior1({100, 100});
    Block block1({600,600});

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        block1.Draw();
        
        warrior1.UpdateStatus();
        if(IsKeyDown(KEY_RIGHT)) {
            if(IsKeyDown(KEY_UP)) {
                warrior1.Jump();
            }
            warrior1.Run(3, 0, "right", true);
        }
        else if(IsKeyDown(KEY_LEFT)) {
            if(IsKeyDown(KEY_UP)) {
                warrior1.Jump();
            }
            warrior1.Run(3, 0, "left", true);
        }
        else if(IsKeyDown(KEY_UP)) {
            warrior1.Idle();
            warrior1.Jump();
        }
        else if(IsKeyDown(KEY_A)) {
            warrior1.Attack();
        }
        else if(IsKeyDown(KEY_G)) {
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
