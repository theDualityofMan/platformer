#include "raylib.h"
#include "unit.h"
#include "warrior.h"
#include "blocks.h"

#include <unordered_map>
#include <string>
#include <vector>

int main() {
    const int monitorWidth = GetMonitorWidth(0);
    const int monitorHeight = GetMonitorHeight(0);

    
    //SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_WINDOW_RESIZABLE);
    SetConfigFlags( FLAG_WINDOW_RESIZABLE);
    InitWindow(monitorWidth, monitorHeight, "Hello Raylib");
    SetTargetFPS(60);

    std::vector<std::vector<int>> map = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    std::vector<Block> blocks;
    std::vector<std::unordered_map<std::string, int>> blockDims;

    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            if (map[y][x] == 1) {
                blocks.emplace_back(Block({(float)(x * 50), (float)(y * 50)}));
                blockDims.push_back({
                    {"x", x * 50},
                    {"y", y * 50},
                    {"width", 50},
                    {"height", 50}
                });
            }
        }
    }
    Warrior warrior1({100, 100});


    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (auto& block : blocks) {
            block.Draw();
        }
        
        warrior1.UpdateStatus();
        warrior1.checkForCollisions(blockDims);
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
