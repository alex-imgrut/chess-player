#include "Piece.h"

Piece::Piece() {}

Piece::Piece(std::string filename, sf::Vector2f position) {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    this->position = position;
}

void Piece::update() {
}

sf::Sprite Piece::getSprite() {
    return sprite;
}
