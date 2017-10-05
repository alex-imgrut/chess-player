#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Piece.h"

class Board
{

private:

    std::map <std::string, Piece> pieces;
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

public:

    Board();
    void update();
    void draw(sf::RenderWindow& window);
};
