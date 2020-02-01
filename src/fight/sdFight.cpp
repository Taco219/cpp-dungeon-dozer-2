#include "sdFight.hpp"

void SdFight::HandleEvent(Event event)
{
    switch (currentFightState)
    {
    case WAIT_FOR_PLAYER_ATT:
        HandleWaitForPlayerAtt(event);
        break;
    case WAIT_FOR_MONSTER_ATT:
        HandleWaitForMontserAtt(event);
        break;
    default:
        break;
    }
}

void SdFight::HandleWaitForPlayerAtt(Event)
{
}

void SdFight::HandleWaitForMontserAtt(Event)
{
}