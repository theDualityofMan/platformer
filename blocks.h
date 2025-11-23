#pragma once

#include "raylib.h"
#include <string>
#include <iostream>
#include <unordered_map>

class Block {
    public:
        Block(Vector2 pos);
        void Draw();
        std::unordered_map<std::string, int> GetDimensions();
    protected:
    private:
        Vector2 position;
};

