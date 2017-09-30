#include "bob.h"

Bob::Bob()
{
    // Associate a texture with the sprite
    m_Texture.loadFromFile("Images/bob.png");
    m_Sprite.setTexture(m_Texture);

    // Set the Bob's initial position
    m_Position.x = 50;
    m_Position.y = 80;
}

// Make the private spite available to the draw() function
Sprite Bob::getSprite()
{
    return m_Sprite;
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Bob::update()
{
    m_Position.x += 10;
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);
}
