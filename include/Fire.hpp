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
     * @brief Speed of the space craft.
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
     * @brief Default constrcutor.
     */
    Fire();

    /**
     * @brief Destructor.
     */
    ~Fire();

    /**
     * @brief Draws the space craft on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);
};

#endif /* FIRE_HPP_INCLUDED */
