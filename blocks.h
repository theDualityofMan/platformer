#pragma once

#include "raylib.h"
#include <string>
#include <iostream>
#include <unordered_map>

struct Block {
        Block(Vector2 pos);
        void Draw();
        std::unordered_map<std::string, int> GetDimensions();
    private:
        Vector2 position;
        Texture2D texture;
};

