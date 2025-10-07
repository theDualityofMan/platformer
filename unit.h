#ifndef UNIT_H
#define UNIT_H

#include "raylib.h"
#include <iostream>

class Unit {
public:
    int health;
    Unit(const char* texturePath, Vector2 pos, int nFrames, int fSpeed);
    void Update();
    void Draw();
    void Move(float dx, float dy);
    void Unload();

private:
    Texture2D texture;
    Vector2 position;
    int frameWidth, frameHeight;
    int numFrames;
    int currentFrame;
    int frameCounter;
    int frameSpeed;
};

class Warrior : public Unit {
public:
    Warrior(const char* texturePath, Vector2 pos, int nFrames, int fSpeed);
    int attackPower;
};

#endif
