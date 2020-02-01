#include "player.hpp"

Player::Player(std::string name, int health, int attack)
    : name(name), health(health), attack(attack)
{
}

std::string Player::GetName() const
{
    return name;
}

int Player::GetHealth() const
{
    return health;
}

int Player::GetAttack() const
{
    return attack;
}

void Player::RecieveDamage(int damage)
{
    health -= damage;
}