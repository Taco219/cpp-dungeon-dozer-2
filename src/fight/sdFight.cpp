#include "sdFight.hpp"

SdFight::SdFight(Console &console, EventGenerator &eventGenerator, Player &player, Monster &monster)
    : console(console), eventGenerator(eventGenerator), player(player), monster(monster)
{
    console.FgthStart(player.GetName(), monster.GetName());
    EnterPlayerTurn();
    currentFightState = PLAYER_TURN;
}

void SdFight::HandleEvent(Event event)
{
    switch (currentFightState)
    {
    case PLAYER_TURN:
        HandlePlayerTurn(event);
        break;
    case MONSTER_TURN:
        HandleMonsterTurn(event);
        break;
    default:
        break;
    }
}

// private
void SdFight::Attack(IMob &attacker, IMob &reciever)
{
    int attackDamage = attacker.GetAttack();
    reciever.RecieveDamage(attackDamage);
    console.FgthMobAttack(attacker, reciever);
}

void SdFight::EnterPlayerTurn()
{
    console.FgthPlayerPickAction();
}

void SdFight::HandlePlayerTurn(Event event)
{
    switch (event)
    {
    case FGT_PLAYER_ATT:
        Attack(player, monster);
        if (monster.GetHealth() > 0)
        {
            currentFightState = MONSTER_TURN;
            EnterMonsterTurn();
        }
        else
        {
            eventGenerator.PushEvent(FGT_MONSTER_DIED);
        }
        break;
    default:
        break;
    }
}

void SdFight::EnterMonsterTurn()
{
    eventGenerator.PushEvent(FGT_MONSTER_ATT);
}

void SdFight::HandleMonsterTurn(Event event)
{
    switch (event)
    {
    case FGT_MONSTER_ATT:
        Attack(monster, player);
        if (player.GetHealth() > 0)
        {
            currentFightState = PLAYER_TURN;
            EnterPlayerTurn();
        }
        else
        {
            eventGenerator.PushEvent(FGT_PLAYER_DIED);
        }
        break;
    default:
        break;
    }
}
