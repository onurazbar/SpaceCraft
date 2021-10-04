/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of SpaceCraft class.
 *
 */

#include "../include/SpaceCraft.hpp"

#include <iostream>
#include <cmath>

SpaceCraft::SpaceCraft(): speed(5.f)
{
    if (!texture.loadFromFile("../images/spacecraft.png"))
    {
        throw "Could not load the image \"spacecraft.png\"!";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(50, 39));
    sprite.setPosition(sf::Vector2f(300, 550));
}

SpaceCraft::~SpaceCraft()
{
}

void SpaceCraft::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void SpaceCraft::move()
{
    float angle = sprite.getRotation();

    float x = speed * std::cos(angle * M_PI / 180);
    float y = speed * std::sin(angle * M_PI / 180);

    sprite.move(sf::Vector2f(x, y));
}

void SpaceCraft::turn(const bool& turn_right)
{
    float angle = sprite.getRotation();

    if (turn_right)
    {
        sprite.setRotation(angle + 5.f);
    }
    else
    {
        sprite.setRotation(angle - 5.f);
    }
}
