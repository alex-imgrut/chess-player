#include "Engine.h"

Engine::Engine()
{
    // Get screen resolution and create main window
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Chess Player", sf::Style::Default);
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
        sf::Event event;
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
void Engine::input(sf::Event event)
{
    if (event.type == sf::Event::Closed) {
        m_Window.close();
    }
}

/*
 * At this place, we shall update all objects in the window
 */
void Engine::update()
{
    // Update all game objects
    board.update();
    piece.update();
}

/*
 " At this place, we shall update all objects in the window
 * and redraw them all
 */
void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(sf::Color::White);

    // List of game objects
    m_Window.draw(board.getSprite());
    m_Window.draw(piece.getSprite());
    
    // Show everything we have just drawn
    m_Window.display();
}
