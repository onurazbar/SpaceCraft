/*
 *
 * @file  Asteroid.cpp
 * @biref This file contains the implementation of Asteroid class.
 *
 */

#include "../include/Asteroid.hpp"

Asteroid::Asteroid()
{
    if (!texture.loadFromFile("../images/asteroid.png"))
    {
        throw "Could not load the image \"asteroid.png\"!";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(50, 40));
    sprite.setPosition(sf::Vector2f(100, 100));
}

Asteroid::~Asteroid()
{
}

void Asteroid::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
