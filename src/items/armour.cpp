#include <armour.hpp>

Armour::Armour(std::string name, int defence)
    : name(name), defence(defence)
{
}

std::string Armour::GetName() const
{
    return name;
}

int Armour::GetDefence() const
{
    return defence;
}