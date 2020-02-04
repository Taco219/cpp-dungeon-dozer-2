#pragma once

#include "console.hpp"
#include "events.hpp"
#include "eventGenerator.hpp"
#include "iMob.hpp"
#include "monster.hpp"
#include "player.hpp"

enum FightState
{
    PLAYER_TURN,
    MONSTER_TURN
};

class SdFight
{
private:
    Console &console;
    EventGenerator &eventGenerator;
    Player &player;
    Monster &monster;

    FightState currentFightState;

    void Attack(IMob &attacker, IMob &reciever);

    void EnterPlayerTurn();
    void HandlePlayerTurn(Event event);

    void EnterMonsterTurn();
    void HandleMonsterTurn(Event event);

public:
    SdFight(Console &console, EventGenerator &eventGenerator, Player &player, Monster &monster);
    void HandleEvent(Event event);
};