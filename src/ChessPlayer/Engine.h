#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Piece.h"

class Engine
{
private:

    // A regular RenderWindow
    sf::RenderWindow window;

    // Game objects
    Board board;

    void input(sf::Event event);
    void update();
    void draw();

public:

    Engine();
    void start();
};
