/*
 *
 * @file  Game.hpp
 * @brief This file defines Game class.
 *
 */

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Background.hpp"
#include "SpaceCraft.hpp"

class Game
{
private:

    /**
     * @brief Main game window.
     */
    sf::RenderWindow window;

    /**
     * @brief Background that displays space view.
     */
    Background background;

    /**
     * @brief Space craft of the game.
     */
    SpaceCraft space_craft;

public:

    /**
     * @brief Default constrcutor.
     */
    Game();

    /**
     * @brief Destructor.
     */
    ~Game();

    /**
     * @brief Starts the gameplay.
     */
    void play();
};

#endif /* GAME_HPP_INCLUDED */
