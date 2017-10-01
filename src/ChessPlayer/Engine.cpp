#include "Engine.h"

Engine::Engine()
{
    // Get screen resolution and create main window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "Chess Player", Style::Default);

    // Load the background into the texture
    // Associate the sprite with the texture
//    Vector2f m_BackgroundPosition = Vector2f(50, 100);
//    m_BackgroundSprite.setPosition(m_BackgroundPosition);
//    m_BackgroundTexture.loadFromFile("Images/board.png");
//    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

/*
 * Once started, Engine will only stop when user closes the Window
 * While running, Engine continuously processes the inputs and redraws
 * the window
 */
void Engine::start()
{

    // Run the program as long as the window is open
    while (m_Window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (m_Window.pollEvent(event))
        {
            input(event);
            update();
            draw();
        }
    }
}

/*
 * At this place, we shall take user's inputs into account and trigger
 * ad hoc behavior on objects in the window
 */
void Engine::input(Event event)
{
    // "close requested" event: we close the window
    if (event.type == Event::Closed) {
        m_Window.close();
    }
}

/*
 * At this place, we shall update all objects in the window
 */
void Engine::update()
{
    // TODO : Use a list of objects
//    m_Bob.update();
    board.update();
}

/*
 " At this place, we shall update all objects in the window
 * and redraw them all
 */
void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);

    // Draw the background
    // TODO : Use a list of objects
//    m_Window.draw(m_BackgroundSprite);
//    m_Window.draw(board.getSprite());
    
    std::array<sf::Sprite, 33> sprites = board.getSprites();
    for (int i = 0; i < 33; i++) {
        m_Window.draw(sprites[i]);
    }

    // Show everything we have just drawn
    m_Window.display();
}
