#include "Piece.h"

Piece::Piece(const std::string& file, sf::Vector2f position)
{
    texture.loadFromFile(file);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Piece::update() {
}

sf::Sprite Piece::getSprite() {
    return Piece::sprite;
}
