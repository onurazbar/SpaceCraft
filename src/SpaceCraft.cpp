/*
 *
 * @file  SpaceCraft.cpp
 * @biref This file contains the implementation of SpaceCraft class.
 *
 */

#include "../include/SpaceCraft.hpp"

#include <cmath>

SpaceCraft::SpaceCraft(): speed(7.5)
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

sf::Sprite& SpaceCraft::getSprite()
{
    return sprite;
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

void SpaceCraft::shoot(std::vector<std::shared_ptr<Fire>>& fires)
{
    float angle = sprite.getRotation();

    float x = sprite.getPosition().x + (60 * std::cos(angle * M_PI / 180));
    float y = sprite.getPosition().y + (60 * std::sin(angle * M_PI / 180));

    fires.push_back(std::make_shared<Fire>(x, y, angle));
}

void SpaceCraft::turn(const bool& turn_right)
{
    float angle = sprite.getRotation();

    if (turn_right)
    {
        sprite.setRotation(angle + 7.5);
    }
    else
    {
        sprite.setRotation(angle - 7.5);
    }
}
