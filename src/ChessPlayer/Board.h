#pragma once
#include <SFML/Graphics.hpp>

class Board
{

private:
    
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

public:

    Board();
    void update();
    sf::Sprite getSprite();
};
