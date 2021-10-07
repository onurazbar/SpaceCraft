/*
 *
 * @file  Fire.cpp
 * @biref This file contains the implementation of Fire class.
 *
 */

#include "../include/Fire.hpp"

#include <cmath>

Fire::Fire(const float& x, const float& y, const float& angle): speed(300.f)
{
    if (!texture.loadFromFile("../images/fire.png"))
    {
        throw "Could not load the image \"fire.png\"!";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(10, 2));
    sprite.setRotation(angle);
    sprite.setPosition(sf::Vector2f(x, y));
}

Fire::~Fire()
{
}

sf::Sprite& Fire::getSprite()
{
    return sprite;
}

void Fire::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Fire::move(const sf::Time& delta_time)
{
    float time_seconds = delta_time.asSeconds();
    float angle = sprite.getRotation();

    float x = speed * time_seconds * std::cos(angle * M_PI / 180);
    float y = speed * time_seconds * std::sin(angle * M_PI / 180);

    sprite.move(sf::Vector2f(x, y));
}
