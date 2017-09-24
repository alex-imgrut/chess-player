#include<SFML\Graphics.hpp>
#include "Pieces.h"
#include "Window.h"

/*bool Move = false;
float dx = 0, dy = 0;*/


Window::Window()
{
    //Screen resolution
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    c_Window.create(sf::VideoMode(resolution.x, resolution.y), "BoardDraw", sf::Style::Default);

    //Pieces Of Chess
    PiecesTexture.loadFromFile("images/pieces.png");
    PiecesSprite.setTexture(PiecesTexture);

    //Board
    BoardTexture.loadFromFile("images/board.png");
    BoardSprite.setTexture(BoardTexture);

    //BoardPosition.x = 300;
    //BoardPosition.y = 400;

   

}

void Window::start()
{
    sf::Clock clock;
    
    //sf::Vector2i pos = sf::Mouse::getPosition(c_Window);

    while (c_Window.isOpen())
    {
        sf::Event e;

        while (c_Window.pollEvent(e))
       
            if (e.type == sf::Event::Closed)
                c_Window.close();
        /*
            if (e.type == sf::Event::MouseButtonPressed)
                if (e.key.code == sf::Mouse::Left)
                    if (PiecesSprite.getGlobalBounds().contains(pos.x, pos.y))
                    {
                        Move = true;
                        dx = pos.x - PiecesSprite.getPosition().x;
                        dy = pos.y - PiecesSprite.getPosition().y;
                    }
            if (e.type == sf::Event::MouseButtonReleased)
                if (e.key.code == sf::Mouse::Left)
                    Move = false;
        */

        }
   // if (Move) PiecesSprite.setPosition(pos.x - dx, pos.y - dy);

        c_Window.clear();
        c_Window.draw(PiecesSprite);
        c_Window.display();
}



void Window::input()
{






}




//void Board::update(float dtAsSeconds)
//}
//c_Button.update(dtAsSeconds);
//}