#include "Meta.h"
#include "../Game.h"

Meta::Meta(Game * game) : GameObject(game)
{

}
void Meta::draw() {
    drawTexture(game->getTexture(goalTexture));
};

