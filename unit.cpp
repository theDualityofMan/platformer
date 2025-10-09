#include "unit.h"

Unit :: Unit(Vector2 pos)
        : position(pos)
    {
    }

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

void Unit::Draw(Texture2D tex, int frameWidth, int frameHeight) {
    if (flip)
    {
        DrawTextureRec(tex, {(float)frameWidth * currentFrame , 0, (float)-frameWidth, (float)frameHeight}, position, WHITE);
    } else
    {
        DrawTextureRec(tex, {(float)frameWidth * currentFrame , 0, (float)frameWidth, (float)frameHeight}, position, WHITE);
    }
}

void Unit::Animate(Texture2D tex, int numFrames, int frameWidth, int frameHeight) {
    Draw(tex, frameWidth, frameHeight);
    Update(numFrames);
}

void Unit::Move(Vector2 delta) {
    position.x += delta.x;
    position.y += delta.y;
}



    
    
