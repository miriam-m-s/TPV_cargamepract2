//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H
#include "GameObject.h";



#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"


    class Car:public GameObject 
    {
        

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
  


public:
    Car(Game * game);
    void draw()override;
    void reiniciacar() {
        vidas = INITIAL_POWER;
    }
    void update();
    void moveup(bool h);
    void movedown(bool h);
    void acelerate(bool h);
    void frenar(bool h);
    void Chocar();
    int Vidas() { return vidas; }
    double Velocidad() { return speed; }

};


#endif //CARGAME_CAR_H
