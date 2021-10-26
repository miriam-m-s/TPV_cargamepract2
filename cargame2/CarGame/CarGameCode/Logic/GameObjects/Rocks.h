#pragma once
class Game;
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"

class Rocks {
 private:
    Point2D<double> pos;
    int w, h;
    Game* game;
    Texture* texture;
public:
    Rocks(Game* game);
    ~Rocks() ;
    void draw(double carx) ;
    void drawTexture(Texture* texture,double carx) ;
    void setDimension(int width, int height);
    double getX() { return pos.getX(); };
    double getY() { return pos.getY(); };
    int getWidth() { return w; };
    int getHeight() { return h; };
    void setPosition(double x, double y);
    SDL_Rect getCollider() ;
};





