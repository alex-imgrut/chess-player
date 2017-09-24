#pragma once
#include <SFML\Graphics.hpp>
#include "Board.h"
#include "Pieces.h"


class Window
{

private:

    sf::RenderWindow c_Window;

    //Sprite and Texture Background
    sf::Sprite c_BackgroundSprite;
    sf::Texture c_BackgroundTexture;

    //Pieces of Chess []
    Pieces c_Pieces;
    sf::Sprite PiecesSprite;
    sf::Texture PiecesTexture;

    //Board
    Board c_Board;
    sf::Vector2f BoardPosition;
    sf::Texture BoardTexture;
    sf::Sprite BoardSprite;

    //Button
    //Button c_Button;

    void input();
    void update(float dtAsSeconds);
    void draw();
public:

    //Constructor
    Window();

    //Call private functions
    void start();
    

};