#include "Board.h"
#include <map>

Board::Board()
{
    // Associate a texture with the sprite
    texture.loadFromFile("Images/board.png");
    sprite.setTexture(texture);

    // Set the Board's initial position
    position.x = 0;
    position.y = 0;
    sprite.setPosition(position);

    // Initialize pieces position
    sf::Vector2u size = texture.getSize();
    float x = float(size.x / 8);

    // TODO: add board offsets
    pieces["a1"] = Piece("Images/white_tower.png", x * sf::Vector2f(0, 7));
    pieces["b1"] = Piece("Images/white_knight.png", x * sf::Vector2f(1, 7));
    pieces["c1"] = Piece("Images/white_bishop.png", x * sf::Vector2f(2, 7));
    pieces["d1"] = Piece("Images/white_queen.png", x * sf::Vector2f(3, 7));
    pieces["e1"] = Piece("Images/white_king.png", x * sf::Vector2f(4, 7));
    pieces["f1"] = Piece("Images/white_bishop.png", x * sf::Vector2f(5, 7));
    pieces["g1"] = Piece("Images/white_knight.png", x * sf::Vector2f(6, 7));
    pieces["h1"] = Piece("Images/white_tower.png", x * sf::Vector2f(7, 7));

    pieces["a2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(0, 6));
    pieces["b2"] = Piece("Images/white_pawn.png", x*  sf::Vector2f(1, 6));
    pieces["c2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(2, 6));
    pieces["d2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(3, 6));
    pieces["e2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(4, 6));
    pieces["f2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(5, 6));
    pieces["g2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(6, 6));
    pieces["h2"] = Piece("Images/white_pawn.png", x * sf::Vector2f(7, 6));

    pieces["a7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(0, 1));
    pieces["b7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(1, 1));
    pieces["c7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(2, 1));
    pieces["d7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(3, 1));
    pieces["e7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(4, 1));
    pieces["f7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(5, 1));
    pieces["g7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(6, 1));
    pieces["h7"] = Piece("Images/black_pawn.png", x * sf::Vector2f(7, 1));

    pieces["a8"] = Piece("Images/black_tower.png", x * sf::Vector2f(0, 0));
    pieces["b8"] = Piece("Images/black_knight.png", x * sf::Vector2f(1, 0));
    pieces["c8"] = Piece("Images/black_bishop.png", x * sf::Vector2f(2, 0));
    pieces["d8"] = Piece("Images/black_queen.png", x * sf::Vector2f(3, 0));
    pieces["e8"] = Piece("Images/black_king.png", x * sf::Vector2f(4, 0));
    pieces["f8"] = Piece("Images/black_bishop.png", x * sf::Vector2f(5, 0));
    pieces["g8"] = Piece("Images/black_knight.png", x * sf::Vector2f(6, 0));
    pieces["h8"] = Piece("Images/black_tower.png", x * sf::Vector2f(7, 0));
}

void Board::update() {
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    
    pieces["a1"].draw(window);
    pieces["b1"].draw(window);
    pieces["c1"].draw(window);
    pieces["d1"].draw(window);
    pieces["e1"].draw(window);
    pieces["f1"].draw(window);
    pieces["g1"].draw(window);
    pieces["h1"].draw(window);

    pieces["a2"].draw(window);
    pieces["b2"].draw(window);
    pieces["c2"].draw(window);
    pieces["d2"].draw(window);
    pieces["e2"].draw(window);
    pieces["f2"].draw(window);
    pieces["g2"].draw(window);
    pieces["h2"].draw(window);

    pieces["a8"].draw(window);
    pieces["b8"].draw(window);
    pieces["c8"].draw(window);
    pieces["d8"].draw(window);
    pieces["e8"].draw(window);
    pieces["f8"].draw(window);
    pieces["g8"].draw(window);
    pieces["h8"].draw(window);

    pieces["a7"].draw(window);
    pieces["b7"].draw(window);
    pieces["c7"].draw(window);
    pieces["d7"].draw(window);
    pieces["e7"].draw(window);
    pieces["f7"].draw(window);
    pieces["g7"].draw(window);
    pieces["h7"].draw(window);

/*    std::map<std::string, Piece>::iterator it;
    for (it = pieces.begin(); it != pieces.end(); it++)
    {
        pieces[it].draw(window);
    }*/
}
