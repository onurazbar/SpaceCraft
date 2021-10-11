/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of Game class.
 *
 */

#include "../include/Game.hpp"

#include <iostream>
#include <cmath>
#include <ctime>

Game::Game(): game_over(false)
{
    window.create(sf::VideoMode(1600, 940), "Space Craft Game");

    std::srand(std::time(0));
}

Game::~Game()
{
}

void Game::checkAsteroidOutOfWindow()
{
    sf::Vector2u window_size = window.getSize();

    for (unsigned int i = 0; i < asteroids.size(); i++)
    {
        sf::Vector2f position = asteroids[i]->getSprite().getPosition();

        if ((position.x < -50) ||
            (position.y < -50) ||
            (position.x > (window_size.x + 50)) ||
            (position.y > (window_size.y + 50)))
        {
            asteroids.erase(asteroids.begin() + i);
        }
    }
}

void Game::checkFireOutOfWindow()
{
    sf::Vector2u window_size = window.getSize();

    for (unsigned int i = 0; i < fires.size(); i++)
    {
        sf::Vector2f position = fires[i]->getSprite().getPosition();

        if ((position.x < 0) ||
            (position.y < 0) ||
            (position.x > window_size.x) ||
            (position.y > window_size.y))
        {
            fires.erase(fires.begin() + i);
        }
    }
}

void Game::checkFireHitAsteroid()
{
    for (unsigned int i = 0; i < fires.size(); i++)
    {
        for (unsigned int j = 0; j < asteroids.size(); j++)
        {
            if (fires[i]->getSprite().getGlobalBounds().intersects(asteroids[j]->getSprite().getGlobalBounds()))
            {
                sf::Vector2f position = asteroids[j]->getSprite().getPosition();

                fires.erase(fires.begin() + i);
                asteroids.erase(asteroids.begin() + i);

                explosions.push_back(std::make_shared<Explosion>(position.x, position.y));
            }
        }
    }

    for (unsigned int i = 0; i < explosions.size(); i++)
    {
        if (explosions[i]->getCurrentFrame() == (explosions[i]->getFramesNumber() - 1))
        {
            explosions.erase(explosions.begin() + i);
        }
    }
}

void Game::checkGameOver()
{
    for (unsigned int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i]->getSprite().getGlobalBounds().intersects(space_craft.getSprite().getGlobalBounds()))
        {
            game_over = true;
            break;
        }
    }
}

void Game::generateAsteroids(sf::Time& elapsed_time, sf::Time& asteroid_generate_time)
{
    if ((elapsed_time - asteroid_generate_time) > sf::seconds(2.f))
    {
        asteroid_generate_time = elapsed_time;

        bool too_close = true;
        int x = 0;
        int y = 0;

        const sf::Vector2f craft_position = space_craft.getSprite().getPosition();

        while (too_close)
        {
            x = (std::rand() % 1500) + 50;
            y = (std::rand() % 840) + 50;

            if ((std::abs(craft_position.x - static_cast<float>(x)) > 100) ||
                (std::abs(craft_position.y - static_cast<float>(y)) > 100))
            {
                too_close = false;
            }
        }

        asteroids.push_back(std::make_shared<Asteroid>(static_cast<float>(x), static_cast<float>(y)));
    }
}

void Game::play()
{
    std::cout << "Game::play()" << std::endl;

    sf::Time elapsed_time;
    sf::Time asteroid_generate_time;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time delta_time = clock.restart();

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        space_craft.turn(true);
                    }
                    else if (event.key.code == sf::Keyboard::Left)
                    {
                        space_craft.turn(false);
                    }
                    else if (event.key.code == sf::Keyboard::Up)
                    {
                        space_craft.move();
                    }
                    else if (event.key.code == sf::Keyboard::Space)
                    {
                        space_craft.shoot(fires);
                    }
                    else if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;

                default:
                    break;
            }
        }

        elapsed_time += delta_time;

        generateAsteroids(elapsed_time, asteroid_generate_time);

        for (auto& fire : fires)
        {
            fire->move(delta_time);
        }

        for (auto& asteroid : asteroids)
        {
            asteroid->move(delta_time);
        }

        checkAsteroidOutOfWindow();
        checkFireOutOfWindow();
        checkFireHitAsteroid();

        for (auto& explosion : explosions)
        {
            explosion->updateFrame(elapsed_time);
        }

        checkGameOver();

        window.clear();

        background.draw(window);
        space_craft.draw(window);

        for (auto& fire : fires)
        {
            fire->draw(window);
        }

        for (auto& asteroid : asteroids)
        {
            asteroid->draw(window);
        }

        for (auto& explosion : explosions)
        {
            explosion->draw(window);
        }

        if (game_over)
        {
            message_box.draw(window, 100);
        }

        window.display();

        if (game_over)
        {
            sf::sleep(sf::milliseconds(5000));
            window.close();
        }
    }
}
