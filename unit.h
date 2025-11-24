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

        void Draw(Texture2D tex, float offsetX = 0, float offsetY = 0);
        void Update(int numFrames);
        void Animate(Texture2D tex, int numFrames, int offsetX = 0, int offsetY = 0);
        void ApplyGravity();

        void Move(Vector2 delta);

        virtual ~Unit();

        void loadTexturesFromChild();
        virtual std::unordered_map<std::string, std::string> getTexturePaths() const = 0;

        Texture2D getTexture(const std::string& name) const;
        void checkForCollisions(std::vector<std::unordered_map<std::string, int>> dims);

    protected:
        //TEXTURE STUFF DONT TOUCH
        std::unordered_map<std::string, Texture2D> textures;
        int currentFrame = 0;
        float frameTime = 0.1f; // Time per frame in seconds
        float elapsedTime = 0.0f; // Time since last frame change
        bool flip = false;
        int frameWidth;


        //GAME VARIABLES
        bool isJumping = false;
        bool isGrounded = true;
        float gravity = 1.98f;
        int height;
        int width;

    private:
        Vector2 position;
        
};

