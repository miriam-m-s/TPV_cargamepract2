#include "Rocks.h"
#include "../Game.h"
Rocks::Rocks(Game* game) {
    this->game = game;
    texture = nullptr;

}
Rocks::~Rocks()
{
}
;
void Rocks::setDimension(int width, int height) {
    w = width;
    h = height;
};

void  Rocks::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};
void Rocks::draw(double carx) {
    drawTexture(game->getTexture(rockTexture), carx);
    
};
void Rocks::drawTexture(Texture* texture, double carx) {

    int dX = game->getOrigin().getX();//1
    int dY = game->getOrigin().getY();//0

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
};
SDL_Rect Rocks::getCollider() {
    //forma un cuadrado
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight()
    };
};