/*
 *
 * @file  Asteroid.hpp
 * @brief This file defines Asteroid class.
 *
 */

#ifndef ASTEROID_HPP_INCLUDED
#define ASTEROID_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Asteroid
{
private:

    /**
     * @brief Angle for linear velocity.
     */
    float angle;

    /**
     * @brief Angular speed of the asteroid.
     */
    float angular_speed;

    /**
     * @brief Linear speed of the asteroid.
     */
    float linear_speed;

    /**
     * @brief Texture of the asteroid.
     */
    sf::Texture texture;

    /**
     * @brief Sprite of the asteroid.
     */
    sf::Sprite sprite;

public:

    /**
     * @brief Parameterized constructor.
     * @param x x position of the asteroid.
     * @param y y position of the asteroid.
     */
    Asteroid(const float& x, const float& y);

    /**
     * @brief Destructor.
     */
    ~Asteroid();

    /**
     * @brief Gets sprite of the asteroid.
     * @return Returns sprite.
     */
    sf::Sprite& getSprite();

    /**
     * @brief Draws the space craft on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Rotates and moves the asteroid.
     * @param delta_time Time elapsed since last frame.
     */
    void move(const sf::Time& delta_time);
};

#endif /* ASTEROID_HPP_INCLUDED */
