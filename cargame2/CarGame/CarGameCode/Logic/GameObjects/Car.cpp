//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game *game){
    this->game = game;
    texture = nullptr;

}

void Car::setDimension(int width, int height){
    w = width;
    h = height;
};

void  Car::setPosition(double x, double y){
    pos = Point2D<double>(x, y);
};
void Car::moveup(bool h) {
    up = h;
}
void Car::movedown(bool h) {
    down = h;
}

void Car::acelerate(bool h)
{
    acel = h;
}

void Car::frenar(bool h)
{
    fren = h;
}
void Car::Chocar() {
    //SI COLISIONA SE RESTAN LAS VIDAS
   colision = true;
   vidas--;
}
void Car::update() {
    ejey = 0;
    //COLISION
    if (colision) {
        speed = 0;
        ejey = 0;
        colision = false;
    }
    //SUBE EL COCHE
    else if (up&& getY() >= this->getHeight() / 2) ejey = -VSPEED; 
    //BAJA EL COCHE
    else if (down&& getY() <= game->getWindowHeight() - this->getHeight() / 2)ejey = VSPEED;
    //ACELERA
    else if (acel && (speed <= MAX_SPEED)) {
        if (speed == 0) speed=1;
        else speed *= ACCELERATION;
    }  
    //FRENA
    else if (fren) speed *= DECELERATION;
    pos = Point2D<double>(getX() + 1*speed, getY()+ejey);
   
}


void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}


void Car::drawTexture(Texture *texture) {
    int dX = game->getOrigin().getX();//1
    int dY = game->getOrigin().getY();//0

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h};
    texture->render(textureBox);
}


SDL_Rect Car::getCollider(){
    //forma un cuadrado
    return { int(getX() - getWidth()),
             int(getY() - getHeight()/2),
             getWidth(),
             getHeight()};
}