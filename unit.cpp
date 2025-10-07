#include "unit.h"

Unit :: Unit(const char* texturePath, Vector2 pos, int nFrames, int fSpeed)
        : position(pos), numFrames(nFrames),
          currentFrame(0), frameCounter(0), frameSpeed(fSpeed)
    {
        texture = LoadTexture(texturePath);
        frameWidth  = texture.width / numFrames;  // ✅ auto-calc width
        frameHeight = texture.height;   
        std::cout << "Texture loaded: " << texture.width << "x" << texture.height << "\n";
    }

    // Update animation
void Unit :: Update() {
        frameCounter++;
        if (frameCounter >= frameSpeed) {
            currentFrame++;
            if (currentFrame >= numFrames) currentFrame = 0;
            frameCounter = 0;
        }
    }

    // Draw current frame
void Unit :: Draw() {
        Rectangle sourceRec = { (float)(currentFrame * frameWidth), 0, (float)frameWidth, (float)frameHeight };
        DrawTextureRec(texture, sourceRec, position, WHITE);
    }

    // Cleanup
void Unit :: Unload() {
        UnloadTexture(texture);
    }
    
    // Optional: move unit
void Unit :: Move(float dx, float dy) {
        position.x += dx;
        position.y += dy;
    }


Warrior :: Warrior(const char* texturePath, Vector2 pos, int nFrames, int fSpeed)
        : Unit(texturePath, pos, nFrames, fSpeed) {
            attackPower = 25;
        }  
    
    
