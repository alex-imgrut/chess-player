#include "Piece.h"

Piece::Piece()
{
    // Associate a texture with the sprite
    //texture.loadFromFile("Images/board.png");
    texture.loadFromFile("Images/black_pawn.png");
    sprite.setTexture(texture);

    // Set the Piece initial position
    position.x = 300;
    position.y = 300;
    sprite.setPosition(position);
}

void Piece::update() {
}

sf::Sprite Piece::getSprite() {
    return Piece::sprite;
}
