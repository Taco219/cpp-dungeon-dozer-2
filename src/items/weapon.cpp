#include <weapon.hpp>

Weapon::Weapon(std::string name, int damage) : name(name), damage(damage)
{
}

std::string Weapon::GetName() const
{
    return name;
}

int Weapon::GetDamage() const
{
    return damage;
}