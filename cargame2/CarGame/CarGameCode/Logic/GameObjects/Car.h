//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"

class Car {

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const double VSPEED = 5;
    const double MAX_SPEED = 10;
    double ejey = 0;
    double speed=0;
    const int INITIAL_POWER = 3;
    bool up=false, down=false,acel=false,fren=false;
    bool colision = false;
    int vidas=INITIAL_POWER;
    Point2D<double> pos;
    int w, h;
    Game *game;
    Texture *texture;


public:
    Car(Game *game);
    ~Car() { 
  
    }
    void draw();
    void reiniciacar() {
        vidas = INITIAL_POWER;
    }
    void update();
    void drawTexture(Texture* texture);
    void moveup(bool h);
    void movedown(bool h);
    void acelerate(bool h);
    void frenar(bool h);
    void Chocar();
    void setDimension(int width, int height);
    int Vidas() { return vidas; }
    double Velocidad() { return speed; }
    double getX() {return pos.getX();};
    double getY() {return pos.getY();};
    int getWidth() {return w;};
    int getHeight() {return h;};

    void setPosition(double x, double y);

    SDL_Rect getCollider();
};


#endif //CARGAME_CAR_H
