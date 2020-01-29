#include "game.hpp"

#include <iostream>

Game::Game(EventGenerator &eventGenerator, SdFight &fight)
    : eventGenerator(eventGenerator), fight(fight)
{
    isPlaying = true;
}

void Game::Run()
{
    while (isPlaying)
    {
        Event event = eventGenerator.GetEvent();

        if (event != NO_EVENT)
        {
            fight.HandleEvent(event);
        }
    }
    std::cout << "HELLO" << std::endl;
}