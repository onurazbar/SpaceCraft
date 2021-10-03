/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of Background class.
 *
 */

#include "../include/Background.hpp"

Background::Background()
{
    if (!texture.loadFromFile("../images/space_re.png"))
    {
        throw "Could not load the image \"space.png\"!";
    }

    sprite.setTexture(texture);
}

Background::~Background()
{
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
