#include "blocks.h"

Block::Block (Vector2 pos) : position(pos){
    position = pos;
}
void Block :: Draw () {
    DrawRectangle(position.x, position.y, 50, 50, RED);
}

std::unordered_map<std::string, int> Block :: GetDimensions() {

    std::unordered_map<std::string, int> dims = {
        {"x", (int)position.x},
        {"y", (int)position.y},
        {"width", 50},
        {"height", 50}
    };
    return dims;
}