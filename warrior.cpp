#include "warrior.h"

Warrior :: Warrior(Vector2 pos)
        : Unit(pos) {
            position = pos;
            loadTexturesFromChild();
        }  

std::unordered_map<std::string, std::string> Warrior::getTexturePaths() const {
    std::unordered_map<std::string, std::string> paths; 
    return {
        {"idle", "./assets/warrior/Warrior_Idle.png"},
        {"run", "./assets/warrior/Warrior_Run.png"},
        {"attack1", "./assets/warrior/Warrior_Attack1.png"},
        {"attack2", "./assets/warrior/Warrior_Attack2.png"},
        {"guard", "./assets/warrior/Warrior_Guard.png"}
    };
}

void Warrior::Idle() { 
    tex = getTexture("idle");
    Animate(tex, 8, 192, 192);
}

void Warrior::Run(int deltaX, int deltaY, std::string dir, bool move) { 
    if(move){
        if (std::string(dir) == "left"){
            flip = true;
            deltaX = -deltaX;
        }
        if (std::string(dir) == "right"){
            flip = false;
        }
        Move({(float)deltaX, (float)deltaY});
    }
    tex = getTexture("run");
    Animate(tex, 6, 192, 192);
}

void Warrior::Attack() {
    tex = getTexture("attack1");
    if (currentFrame == 3 && tex.id == getTexture("attack1").id) {
        tex = getTexture("attack2");
    } else if (currentFrame == 3 && tex.id == getTexture("attack2").id) {
        tex = getTexture("attack1");
    }
    Animate(tex, 4, 192, 192);
}

void Warrior::Guard() { 
    tex = getTexture("guard");
    Animate(tex, 6, 192, 192);
}

