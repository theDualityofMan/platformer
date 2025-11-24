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
    void Run(int deltaX, int deltaY, std::string dir, bool move = true);
    void Idle();
    void Jump();
    void UpdateStatus();

private:
    Texture2D tex;

    float jumpClock = 0.0f;

};