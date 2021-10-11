/*
 *
 * @file  Explosion.cpp
 * @biref This file contains the implementation of Explosion class.
 *
 */

#include "../include/Explosion.hpp"

Explosion::Explosion(const float& x, const float& y): current_frame(0), frames_number(16), sprite_size(150, 150)
{
    if (!texture.loadFromFile("../images/explosion.png"))
    {
        throw "Could not load the image \"explosion.png\"!";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(64, 64));
    sprite.setPosition(sf::Vector2f(x, y));
}

Explosion::~Explosion()
{
}

int Explosion::getCurrentFrame()
{
    return current_frame;
}

int Explosion::getFramesNumber()
{
    return frames_number;
}

void Explosion::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Explosion::updateFrame(const sf::Time& elapsed_time)
{
    if ((elapsed_time - frame_render_time) > sf::milliseconds(75))
    {
        current_frame++;
        frame_render_time = elapsed_time;
    }

    sprite.setTextureRect(sf::IntRect((current_frame  % 4) * sprite_size.x,
                       static_cast<int>(current_frame / 4) * sprite_size.y, sprite_size.x, sprite_size.y));
}
