#include "Piece.h"

Piece::Piece() {
    // ...
}

Piece::Piece(const std::string& file, sf::Vector2f position)
{
    texture.loadFromFile(file);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Piece::update() {
}

void Piece::draw(sf::RenderWindow& window)
{
// Why is texture lost at that moment? Texture is still there but no longer linked to sprite...
    sprite.setTexture(texture);

    window.draw(sprite);
}
