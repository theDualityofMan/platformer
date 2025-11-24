#include "unit.h"

Unit :: Unit(Vector2 pos)
        : position(pos){}

//Deconstructor to unload textures on window close
Unit::~Unit() {
    for (auto& pair : textures) {
        UnloadTexture(pair.second);
    }
    textures.clear();
}

//Load textures from child class
void Unit::loadTexturesFromChild() {
    auto paths = getTexturePaths();

    for (const auto& pair : paths) {
        const std::string& name = pair.first;
        const std::string& path = pair.second;
        textures[name] = LoadTexture(path.c_str());
        if (textures[name].id == 0) {
            std::cerr << "Failed to load texture: " << path << std::endl;
        }
        else {
            std::cout << "Loaded texture: " << path << std::endl;
        }
    }
}


Texture2D Unit::getTexture(const std::string& name) const {
    auto it = textures.find(name);
    if (it != textures.end()) {
        return it->second;
    }

    // Return empty texture if not found
    return Texture2D{};
}

void Unit::Update(int numFrames) {
    elapsedTime += 0.016f;
    if (elapsedTime < frameTime) return; // Not enough time has passed for a frame change
    else{
        elapsedTime = 0.0f; // Reset elapsed time
        currentFrame = (currentFrame + 1) % numFrames; // Loop back to first frame if at the end
    }

}

void Unit::Draw(Texture2D tex,float offsetX, float offsetY) {
    if (flip)
    {
        DrawTextureRec(tex, {((float)frameWidth * currentFrame) + offsetX , offsetY, (float)-width, (float)height}, position, WHITE);
    } else
    {
        DrawTextureRec(tex, {((float)frameWidth * currentFrame) + offsetX , offsetY, (float)width, (float)height}, position, WHITE);
    }
}

void Unit::Animate(Texture2D tex, int numFrames, int offsetX, int offsetY) {
    Draw(tex, (float)offsetX, (float)offsetY);
    DrawRectangle(position.x, position.y, (float)width, (float)height, Color{255, 0, 0, 100});
    Update(numFrames);
}

void Unit::Move(Vector2 delta) {
    position.x += delta.x;
    position.y += delta.y;
}

void Unit:: ApplyGravity() {
    if(isGrounded) {
        gravity = 1.98f;
        return;
    };
    if (gravity < 20){
        gravity += 0.5f;
    }
    position.y += gravity;
}

void Unit::checkForCollisions(std::vector<std::unordered_map<std::string, int>> dims){

    isGrounded = false;
    for (auto& dim : dims){
        Rectangle unitRec = {position.x, position.y, width, height};
        Rectangle blockRec = {(float)dim["x"], (float)dim["y"], (float)dim["width"], (float)dim["height"]};

        if (CheckCollisionRecs(unitRec, blockRec)) {

            // Vertical collision (top or bottom)
            if (position.y + height > dim["y"] && position.y < dim["y"] + dim["height"]) {
                if (position.y < dim["y"]) {
                    // Colliding from top
                    position.y = dim["y"] - height;
                    isGrounded = true;
                    isJumping = false;
                } else {
                    // Colliding from bottom
                    position.y = dim["y"] + dim["height"];
                }
            }
            // Horizontal collision (left or right)
            else if (position.x + width > dim["x"] && position.x < dim["x"] + dim["width"]) {
                if (position.x < dim["x"]) {
                    position.x = dim["x"] - width; // Move left
                } else {
                    position.x = dim["x"] + dim["width"]; // Move right
                }
            }
        }

    }
}

    
