#include "monster.hpp"

Monster::Monster(std::string name, int health, int attack)
    : name(name), health(health), attack(attack)
{
}

std::string Monster::GetName() const
{
    return name;
}

int Monster::GetHealth() const
{
    return health;
}

int Monster::GetAttack() const
{
    return attack;
}

void Monster::RecieveDamage(int damage)
{
    health -= damage;
}
