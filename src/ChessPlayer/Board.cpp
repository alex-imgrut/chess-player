#include<SFML/Graphics.hpp>
#include "Board.h"

Board::Board()
{
    // Associate a texture with the sprite
    texture.loadFromFile("Images/board.png");
    sprite.setTexture(texture);

    // Set the Bob's initial position
    position.x = 10;
    position.y = 10;

    // ...
    for (int i = 0; i < 32; i++) {
        pieces[i] = Piece("Image/white_pawn.png", sf::Vector2f(50, 10 * i));
    }
}

sf::Sprite Board::getSprite() {
    return Board::sprite;
}

std::array<sf::Sprite, 33> Board::getSprites() {
    std::array<sf::Sprite, 33> sprites;
    sprites[0] = Board::sprite;
    for (int i = 0; i < 32; i++) {
        sprites[i+1] = pieces[i].getSprite();
    }
    return sprites;
}

void Board::update() {
    for (int i = 0; i < 32; i++) {
        pieces[i].update();
    }
}
