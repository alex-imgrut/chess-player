#pragma once
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include <array>

class Board
{

private:
    
    // Chess pieces
    Piece pieces[32];

    // Position of The Board on the Window
    sf::Vector2f position;

    // Board sprite and a texture
    sf::Sprite sprite;
    sf::Texture texture;

public:

    // Constructor
    Board();

    // Send a copy of board sprite to renderer manager
    sf::Sprite getSprite();
    std::array<sf::Sprite, 33> getSprites();

    // We will call this function once every frame
    void update();

};
