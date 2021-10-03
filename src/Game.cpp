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

void Game::play()
{
    std::cout << "Game::play()" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();

        background.draw(window);

        window.display();
    }
}
