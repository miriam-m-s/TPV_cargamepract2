//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Rocks.h"
#include "GameObjects/Meta.h"


using namespace std;

class Game{

    
private:
    string name;
    bool doExit;
    const int nroc = 20;
    int roadLength;
    int width, height;
    int numrocks = 0;
    double timegame = 0;
    double timefinal = 0;
    Car *car = nullptr;
    Meta* metafin = nullptr;
    vector<Rocks*> roc;
    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;
    double distance = 0;
    bool ganar = false;
    bool perder = false;
    void eliminarpiedras();
    void Colisiones();
    void setrandomposition(int i);
public:
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    const unsigned int ROCKS_WIDTH = 50;
    const unsigned  int ROCKS_HEIGHT = 50;
    const unsigned int META_WIDTH = 50;
    const unsigned  int META_HEIGHT = 500;
    Game(string name, int width, int height, int roadLength);
    ~Game();
    void startGame();
    void update();
    void draw();
    void setUserExit();
    bool isUserExit();
    bool doQuit();
    int getWindowWidth();
    int getWindowHeight();
    void reiniciar();
    Point2D<int> getOrigin();
    string getGameName();
    void Menu();
    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});
    void procesaInput(bool u,bool d,bool a,bool f);
    void subir(bool s);
    void bajar(bool b);
    void acelerar(bool a);
    void frenar(bool f);
    void drawInfo();
    bool Ganar();
    bool Perder();
    void Interfazfinal();
};


#endif //CARGAME_GAME_H
