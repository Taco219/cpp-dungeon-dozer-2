#pragma once

#include "events.hpp"

enum FightState
{
    WAIT_FOR_PLAYER_ATT,
    WAIT_FOR_MONSTER_ATT
};

class SdFight
{
private:
    FightState currentFightState;

    void HandleWaitForPlayerAtt(Event event);
    void HandleWaitForMontserAtt(Event event);

public:
    void HandleEvent(Event event);
};