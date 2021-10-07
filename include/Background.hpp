/*
 *
 * @file  Background.hpp
 * @brief This file defines Background class.
 *
 */

#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Background
{
private:

    /**
     * @brief Texture of the background.
     */
    sf::Texture texture;

    /**
     * @brief Sprite of the background.
     */
    sf::Sprite sprite;

public:

    /**
     * @brief Default constructor.
     */
    Background();

    /**
     * @brief Destructor.
     */
    ~Background();

    /**
     * @brief Draws the background on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);
};

#endif /* BACKGROUND_HPP_INCLUDED */
