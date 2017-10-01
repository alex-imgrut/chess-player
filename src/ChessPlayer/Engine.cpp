#include "Engine.h"

Engine::Engine()
{
    // Get screen resolution and create main window
    unsigned desktopWidth = sf::VideoMode::getDesktopMode().width;
    unsigned desktopHeight = sf::VideoMode::getDesktopMode().height;
    window.create(sf::VideoMode(desktopWidth, desktopHeight), "Chess Player", sf::Style::Default);
}

/*
 * Once started, Engine will only stop when user closes the Window
 * While running, Engine continuously processes the inputs and redraws
 * the window
 */
void Engine::start()
{

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
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
        window.close();
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
    window.clear(sf::Color::White);

    // List of game objects
    window.draw(board.getSprite());
    window.draw(piece.getSprite());
    
    // Show everything we have just drawn
    window.display();
}
