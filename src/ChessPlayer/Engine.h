#pragma once
#include <SFML/Graphics.hpp>
#include "Bob.h"
#include "Board.h""

using namespace sf;

class Engine
{
private:

    // A regular RenderWindow
    RenderWindow m_Window;
    
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;

    // Game objects
    // TODO: define a list of objects
//    Bob m_Bob;
    Board board;

    // Private functions for internal use only
    void input(Event event);
    void update();
    void draw();

public:
    // The Engine constructor
    Engine();

    // start will call all the private functions
    void start();
};
