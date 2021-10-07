/*
 *
 * @file  Asteroid.cpp
 * @biref This file contains the implementation of Asteroid class.
 *
 */

#include "../include/Asteroid.hpp"

#include <iostream>
#include <cmath>
#include <ctime>

Asteroid::Asteroid(): angular_speed(200.f), linear_speed(100.f)
{
    if (!texture.loadFromFile("../images/asteroid.png"))
    {
        throw "Could not load the image \"asteroid.png\"!";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(50, 40));
    sprite.setPosition(sf::Vector2f(100, 100));

    std::srand(std::time(0));
    float k = static_cast<float>(std::rand()) / RAND_MAX;

    angle = k * 2 * M_PI;
}

Asteroid::~Asteroid()
{
}

void Asteroid::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Asteroid::move(const sf::Time& delta_time)
{
    float time_seconds = delta_time.asSeconds();

    float x = time_seconds * linear_speed * std::cos(angle);
    float y = time_seconds * linear_speed * std::sin(angle);

    sprite.move(sf::Vector2f(x, y));

    float rotation_angle = sprite.getRotation();

    sprite.setRotation(rotation_angle + (time_seconds * angular_speed));
}
