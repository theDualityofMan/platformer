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
    Warrior warrior2({300, 100});
    Warrior warrior3({500, 100});
    Warrior warrior4({700, 100});

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        warrior1.Attack();
        warrior2.Guard();
        warrior3.Run();
        warrior4.Idle();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
