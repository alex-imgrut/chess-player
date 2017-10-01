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
    Piece(std::string filename, sf::Vector2f position);
    void update();
    sf::Sprite getSprite();
};
