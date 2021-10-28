#pragma once
//
// Created by eys on 21/8/21.
//

#include "GameObject.h";
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"

class Meta:public GameObject {


public:
    Meta(Game*game);
    void draw();
    void update() {};
   
};









