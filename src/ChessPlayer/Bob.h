#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bob
{

private:

    // Where is Bob
    Vector2f m_Position;

    // Of course we will need a sprite and a texture
    Sprite m_Sprite;
    Texture m_Texture;

public:

    // We will set Bob up in the constructor
    Bob();

    // Send a copy of the sprite to main
    Sprite getSprite();

    // We will call this function once every frame
    void update();
};
