#include "player.hpp"

Player::Player(std::string name, int health, Inventory inventory)
    : name(name), health(health), inventory(inventory)
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
    return inventory.GetTotalDamage();
}

void Player::RecieveDamage(int incommingDamage)
{
    int damage = incommingDamage - inventory.GetTotalDefence();
    if (damage > 0)
    {
        health -= damage;
    }
}