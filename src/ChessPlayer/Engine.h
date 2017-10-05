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
    int x = 75;
    Board board;
    Piece a1 = Piece("Images/white_tower.png", sf::Vector2f(0 * x, 7 * x));
    Piece b1 = Piece("Images/white_knight.png", sf::Vector2f(1 * x, 7 * x));
    Piece c1 = Piece("Images/white_bishop.png", sf::Vector2f(2 * x, 7 * x));
    Piece d1 = Piece("Images/white_queen.png", sf::Vector2f(3 * x, 7 * x));
    Piece e1 = Piece("Images/white_king.png", sf::Vector2f(4 * x, 7 * x));
    Piece f1 = Piece("Images/white_bishop.png", sf::Vector2f(5 * x, 7 * x));
    Piece g1 = Piece("Images/white_knight.png", sf::Vector2f(6 * x, 7 * x));
    Piece h1 = Piece("Images/white_tower.png", sf::Vector2f(7 * x, 7 * x));
    Piece a2 = Piece("Images/white_pawn.png", sf::Vector2f(0 * x, 6 * x));
    Piece b2 = Piece("Images/white_pawn.png", sf::Vector2f(1 * x, 6 * x));
    Piece c2 = Piece("Images/white_pawn.png", sf::Vector2f(2 * x, 6 * x));
    Piece d2 = Piece("Images/white_pawn.png", sf::Vector2f(3 * x, 6 * x));
    Piece e2 = Piece("Images/white_pawn.png", sf::Vector2f(4 * x, 6 * x));
    Piece f2 = Piece("Images/white_pawn.png", sf::Vector2f(5 * x, 6 * x));
    Piece g2 = Piece("Images/white_pawn.png", sf::Vector2f(6 * x, 6 * x));
    Piece h2 = Piece("Images/white_pawn.png", sf::Vector2f(7 * x, 6 * x));
    Piece a7 = Piece("Images/black_pawn.png", sf::Vector2f(0 * x, 1 * x));
    Piece b7 = Piece("Images/black_pawn.png", sf::Vector2f(1 * x, 1 * x));
    Piece c7 = Piece("Images/black_pawn.png", sf::Vector2f(2 * x, 1 * x));
    Piece d7 = Piece("Images/black_pawn.png", sf::Vector2f(3 * x, 1 * x));
    Piece e7 = Piece("Images/black_pawn.png", sf::Vector2f(4 * x, 1 * x));
    Piece f7 = Piece("Images/black_pawn.png", sf::Vector2f(5 * x, 1 * x));
    Piece g7 = Piece("Images/black_pawn.png", sf::Vector2f(6 * x, 1 * x));
    Piece h7 = Piece("Images/black_pawn.png", sf::Vector2f(7 * x, 1 * x));
    Piece a8 = Piece("Images/black_tower.png", sf::Vector2f(0 * x, 0 * x));
    Piece b8 = Piece("Images/black_knight.png", sf::Vector2f(1 * x, 0 * x));
    Piece c8 = Piece("Images/black_bishop.png", sf::Vector2f(2 * x, 0 * x));
    Piece d8 = Piece("Images/black_queen.png", sf::Vector2f(3 * x, 0 * x));
    Piece e8 = Piece("Images/black_king.png", sf::Vector2f(4 * x, 0 * x));
    Piece f8 = Piece("Images/black_bishop.png", sf::Vector2f(5 * x, 0 * x));
    Piece g8 = Piece("Images/black_knight.png", sf::Vector2f(6 * x, 0 * x));
    Piece h8 = Piece("Images/black_tower.png", sf::Vector2f(7 * x, 0 * x));

    void input(sf::Event event);
    void update();
    void draw();

public:

    Engine();
    void start();
};
