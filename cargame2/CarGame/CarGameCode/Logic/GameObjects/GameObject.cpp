#include "GameObject.h"
#include "../Game.h"
//
// Created by eys on 21/8/21.
//

GameObject::GameObject(Game* game) {
    this->game = game;
    texture = nullptr;
    if (this->game == nullptr)cout << "go null game";
};

void GameObject::setDimension(double width, double height) {
    w = width;
    h = height;
};

void  GameObject::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};

void GameObject::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();//1
    int dY = game->getOrigin().getY();//0

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}


SDL_Rect GameObject::getCollider() {
    //forma un cuadrado
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}

bool GameObject::collide(SDL_Rect other)
{
    return SDL_HasIntersection(&getCollider(), &other);
}

