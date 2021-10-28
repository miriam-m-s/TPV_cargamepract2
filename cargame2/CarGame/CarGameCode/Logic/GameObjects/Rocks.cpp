#include "Rocks.h"
#include "../Game.h"

Rocks::Rocks(Game *game): GameObject(game)
{
}
void Rocks::draw() {
    drawTexture(game->getTexture(rockTexture));   
};
