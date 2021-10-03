/*
 *
 * @file  Game.hpp
 * @brief This file defines SpaceCraft class.
 *
 */

#ifndef SPACECRAFT_HPP_INCLUDED
#define SPACECRAFT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class SpaceCraft
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
     * @brief Default constrcutor.
     */
    SpaceCraft();

    /**
     * @brief Destructor.
     */
    ~SpaceCraft();

    /**
     * @brief Draws the space craft on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);
};

#endif /* SPACECRAFT_HPP_INCLUDED */
