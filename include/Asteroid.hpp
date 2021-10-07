/*
 *
 * @file  Game.hpp
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
    Asteroid();

    /**
     * @brief Destructor.
     */
    ~Asteroid();

    /**
     * @brief Draws the space craft on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);
};

#endif /* ASTEROID_HPP_INCLUDED */
