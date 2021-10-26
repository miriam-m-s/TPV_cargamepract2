//
// Created by eys on 20/8/21.
//

#include "ViewController.h"

ViewController::ViewController(Game *_game) {
    game = _game;
    cout << "[DEBUG] frame duration: " << frameDuration() << " ms" << endl;
    initSDL();
    game->setRenderer(renderer);
    game->loadTextures();

}
void ViewController::Menu() {
    clearBackground();
    game->Menu();
    SDL_RenderPresent(renderer);
}
void ViewController::Finjuego() {
    clearBackground();
    game->Interfazfinal();
    SDL_RenderPresent(renderer);
}

void ViewController::run() {
    uint32_t startTime = 0;
    uint32_t frameTime;
    game->startGame();
    estado = menu;
    while (!game->doQuit()) {
        handleEvents();
        switch (estado) {
        case ViewController::menu:
            Menu();
            if (reinicio)estado = juego;

            break;
        case ViewController::juego:
            reinicio = false;
            frameTime = SDL_GetTicks() - startTime;
            if (frameTime >= frameDuration()) {
                clearBackground();
                game->update();
                game->draw();

                //actualiza la pantalla 
                SDL_RenderPresent(renderer);
                startTime = SDL_GetTicks();
                if (game->Ganar() || game->Perder()) estado = fin;
            }
            else {
                //tiempo que se espera para que siempre pasen 33 frames
                SDL_Delay(frameDuration() - frameTime);
            }
            break;
        case ViewController::fin:
            Finjuego();
                if (reinicio) {
                    reinicio = false;
                    estado = menu;
                    game->reiniciar();
                }
             break;
        default:
            break;
        }
   
               
    }
}

void ViewController::clearBackground() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ViewController::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) ){
        if( event.type == SDL_QUIT)
            game->setUserExit();
        if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_UP)  game->subir(true);
            if (key == SDLK_DOWN)game->bajar(true); 
            if(key==SDLK_RIGHT)game->acelerar(true);
            if (key == SDLK_LEFT)game->frenar(true);
            if (key == SDLK_SPACE)reinicio = true;
            
        }
        else {
            game->subir(false);
            game->bajar(false);
            game->acelerar(false);
            game->frenar(false);
        }
    }

}

uint32_t ViewController::frameDuration() {
    return 1000 / FRAME_RATE;//lo que dura cad frame+
}

void ViewController::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(game->getGameName().c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              game->getWindowWidth(),
                              game->getWindowHeight(),
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (window == nullptr || renderer == nullptr)
        throw string("Error creating SDL window or renderer");

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, &screenSurface->clip_rect, 0xFF);
    SDL_UpdateWindowSurface(window);
}

ViewController::~ViewController() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
