#pragma once
#include <SFML/Graphics.hpp>

class Piece
{

private:

    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

public:

    Piece();
    void update();
    sf::Sprite getSprite();
};
