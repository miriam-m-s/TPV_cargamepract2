#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h";

class Rocks : public GameObject {
public:
    Rocks(Game* game);
    void draw() ;
    void update() {};
   
};





