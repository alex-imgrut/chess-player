#pragma once
#include <SFML/Graphics.hpp>

class Piece
{

private:

    sf::Texture texture;
    sf::Sprite sprite;

public:

    Piece();
    Piece(const std::string& file, sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window);
};
