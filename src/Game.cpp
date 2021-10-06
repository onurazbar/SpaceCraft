/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of Game class.
 *
 */

#include "../include/Game.hpp"

#include <iostream>

Game::Game()
{
    window.create(sf::VideoMode(1440, 900), "Space Craft Game");
}

Game::~Game()
{
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

void Game::play()
{
    std::cout << "Game::play()" << std::endl;

    sf::Time elapsed_time;
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

        for (auto& fire : fires)
        {
            fire->move(delta_time);
        }

        checkFireOutOfWindow();

        window.clear();

        background.draw(window);
        space_craft.draw(window);

        for (auto& fire : fires)
        {
            fire->draw(window);
        }

        window.display();
    }
}
