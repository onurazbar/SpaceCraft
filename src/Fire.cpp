/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of Fire class.
 *
 */

#include "../include/Fire.hpp"

Fire::Fire()
{
    if (!texture.loadFromFile("../images/fire.png"))
    {
        throw "Could not load the image \"fire.png\"!";
    }

    sprite.setTexture(texture);
//    sprite.setOrigin(sf::Vector2f(50, 39));
    sprite.setPosition(sf::Vector2f(500, 400));
}

Fire::~Fire()
{
}

void Fire::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
