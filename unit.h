#pragma once

#include "raylib.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>


class Unit {
public:
        int health;
        Unit(Vector2 pos);

        void Draw(Texture2D tex, int frameWidth, int frameHeight);
        void Update(int numFrames);
        void Animate(Texture2D tex, int numFrames, int frameWidth, int frameHeight);
        void ApplyGravity();

        void Move(Vector2 delta);

        virtual ~Unit();

        void loadTexturesFromChild();
        virtual std::unordered_map<std::string, std::string> getTexturePaths() const = 0;

        Texture2D getTexture(const std::string& name) const;

    protected:
        //TEXTURE STUFF DONT TOUCH
        std::unordered_map<std::string, Texture2D> textures;
        int currentFrame = 0;
        float frameTime = 0.1f; // Time per frame in seconds
        float elapsedTime = 0.0f; // Time since last frame change
        bool flip = false;

        //GAME VARIABLES
        bool isJumping = false;
        bool isGrounded = true;
        float gravity = 1.98f;

    private:
        Vector2 position;
        
};

