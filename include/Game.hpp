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
#include "Fire.hpp"
#include "Asteroid.hpp"

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

    /**
     * @brief Fires of the game.
     */
    std::vector<std::shared_ptr<Fire>> fires;

    /**
     * @brief Asteroids of the game.
     */
    std::vector<std::shared_ptr<Asteroid>> asteroids;

    /**
     * @brief Checks the asteroids whether inside the render window. Removes the asteroid if it is out.
     */
    void checkAsteroidOutOfWindow();

    /**
     * @brief Checks the fires whether inside the render window. Removes the fire if it is out.
     */
    void checkFireOutOfWindow();

public:

    /**
     * @brief Default constructor.
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
