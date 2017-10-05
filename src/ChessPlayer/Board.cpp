#include "Board.h"

Board::Board()
{
    // Associate a texture with the sprite
    texture.loadFromFile("Images/board.png");
//    texture.loadFromFile("Images/black_pawn.png");
    sprite.setTexture(texture);

    // Set the Board's initial position
    position.x = 0;
    position.y = 0;
    sprite.setPosition(position);
}

void Board::update() {
}

sf::Sprite Board::getSprite() {
    return Board::sprite;
}