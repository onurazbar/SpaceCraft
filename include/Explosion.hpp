/*
 *
 * @file  Explosion.hpp
 * @brief This file defines Explosion class.
 *
 */

#ifndef EXPLOSION_HPP_INCLUDED
#define EXPLOSION_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Explosion
{
private:

    /**
     * @brief Current frame of explosion animation.
     */
    int current_frame;

    /**
     * @brief Number of frames.
     */
    int frames_number;

    /**
     * @brief Time that previous frame is rendered.
     */
    sf::Time frame_render_time;

    /**
     * @brief Size of each sprite.
     */
    sf::Vector2f sprite_size;

    /**
     * @brief Texture of the explosion animation.
     */
    sf::Texture texture;

    /**
     * @brief Sprite of the explosion animation for rendering.
     */
    sf::Sprite sprite;

public:

    /**
     * @brief Parameterized constructor.
     * @param x x position of the explosion.
     * @param y y position of the explosion.
     */
    Explosion(const float& x, const float& y);

    /**
     * @brief Destructor.
     */
    ~Explosion();

    int getCurrentFrame();

    int getFramesNumber();

    /**
     * @brief Draws explosion animation on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Updates the current frame of explosion animation.
     * @param elapsed_time Elapsed time.
     */
    void updateFrame(const sf::Time& elapsed_time);
};

#endif /* EXPLOSION_HPP_INCLUDED */
