/*
 *
 * @file  Game.hpp
 * @brief This file defines Fire class.
 *
 */

#ifndef FIRE_HPP_INCLUDED
#define FIRE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Fire
{
private:

    /**
     * @brief Speed of the fire.
     */
    float speed;

    /**
     * @brief Texture of the space craft.
     */
    sf::Texture texture;

    /**
     * @brief Sprite of the space craft.
     */
    sf::Sprite sprite;

public:

    /**
     * @brief Parameterized constructor.
     */
    Fire(const float& x, const float& y, const float& angle);

    /**
     * @brief Destructor.
     */
    ~Fire();

    /**
     * @brief Draws the space craft on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Moves the fire on its direction.
     * @param delta_time Time elapsed since last frame.
     */
    void move(const sf::Time& delta_time);
};

#endif /* FIRE_HPP_INCLUDED */
