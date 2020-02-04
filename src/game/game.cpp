#include "game.hpp"

// #include "monster.hpp"
#include "player.hpp"

#include <iostream>

Game::Game(Console &console, EventGenerator &eventGenerator)
    : console(console), eventGenerator(eventGenerator)
{
    isPlaying = true;
}

Game::~Game()
{
    delete fight;
    fight = nullptr;
}

void Game::Run()
{
    Player player = Player("Taco", 100, 10);
    Monster monster = Monster("monster", 20, 1);

    fight = new SdFight(console, eventGenerator, player, monster);

    while (isPlaying)
    {
        Event event = eventGenerator.GetEvent();

        if (event != NO_EVENT)
        {
            switch (event)
            {
            case FGT_PLAYER_DIED:
                std::cout << "Player died \n";
                isPlaying = false;
                break;
            case FGT_MONSTER_DIED:
                std::cout << "Monster died \n";
                isPlaying = false;
                break;
            default:
                fight->HandleEvent(event);
            }
        }
    }
}