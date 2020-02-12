#include "game.hpp"

#include "monster.hpp"
#include "player.hpp"

#include <iostream>

Game::Game(Console &console, EventGenerator &eventGenerator, Player &player)
    : console(console), eventGenerator(eventGenerator), player(player)
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
    Monster monster = Monster("monster", 20, 6);

    fight = new SdFight(console, eventGenerator, player, monster);

    while (isPlaying)
    {
        Event event = eventGenerator.GetEvent();

        if (event != NO_EVENT)
        {
            switch (event)
            {
            case FGT_PLAYER_DIED:
                console.FgthMobDied(player);
                isPlaying = false;
                break;
            case FGT_PLAYER_FLED:
                console.FgthMobFled(player);
                isPlaying = false;
                break;
            case FGT_MONSTER_DIED:
                console.FgthMobDied(monster);
                isPlaying = false;
                break;
            default:
                fight->HandleEvent(event);
            }
        }
    }
}