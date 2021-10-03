/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of SpaceCraft class.
 *
 */

#include "../include/SpaceCraft.hpp"

SpaceCraft::SpaceCraft()
{
    if (!texture.loadFromFile("../images/spacecraft.png"))
    {
        throw "Could not load the image \"spacecraft.png\"!";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(50, 39));
    sprite.setPosition(sf::Vector2f(1000, 550));
}

SpaceCraft::~SpaceCraft()
{
}

void SpaceCraft::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
