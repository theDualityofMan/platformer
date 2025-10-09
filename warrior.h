#pragma once
#include "unit.h"

class Warrior : public Unit {
public:
    Warrior(Vector2 pos);
    std::unordered_map<std::string, std::string> getTexturePaths() const override;

    int attackPower;
    Vector2 position;
    void Attack();
    void Guard();
    void Run();
    void Idle();
private:
    Texture2D tex;

};