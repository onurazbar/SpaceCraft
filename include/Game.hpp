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
#include "Explosion.hpp"
#include "MessageBox.hpp"

class Game
{
private:

    /**
     * @brief Indicates whether the game is ovver or not.
     */
    bool game_over;

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
     * @brief Explosions of the game.
     */
    std::vector<std::shared_ptr<Explosion>> explosions;

    /**
     * @brief Message box for game over case.
     */
    MessageBox message_box;

    /**
     * @brief Checks the asteroids whether inside the render window. Removes the asteroid if it is out.
     */
    void checkAsteroidOutOfWindow();

    /**
     * @brief Checks the fires whether inside the render window. Removes the fire if it is out.
     */
    void checkFireOutOfWindow();

    /**
     * @brief Checks the fires whether hits the asteroid. If there is a hit, asteroid and fire will be removed.
     *        Then explosion animation will be sstarted.
     */
    void checkFireHitAsteroid();

    /**
     * @brief Checks whether an asteroid hits the space craft.
     */
    void checkGameOver();

    /**
     * @brief Generates asteroids with one second intervals.
     * @param elapsed_time Elapsed time since the beginning of the game.
     * @param asteroid_generate_time The time when the last asteroid was generated.
     */
    void generateAsteroids(sf::Time& elapsed_time, sf::Time& asteroid_generate_time);

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
