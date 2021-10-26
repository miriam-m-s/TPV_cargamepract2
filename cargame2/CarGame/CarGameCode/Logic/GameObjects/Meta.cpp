#include "Meta.h"
#include "../Game.h"
Meta::Meta(Game* game) {
    this->game = game;
    texture = nullptr;

};
void Meta::setDimension(int width, int height) {
    w = width;
    h = height;
};

void Meta::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};
void Meta::draw() {
    drawTexture(game->getTexture(goalTexture));

};


void Meta::drawTexture(Texture* texture) {

    int dX = game->getOrigin().getX();//1
    int dY = game->getOrigin().getY();//0

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
};
SDL_Rect Meta::getCollider() {
    //forma un cuadrado
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight()
    };
};
