#pragma once

#include <string>

class Weapon
{
private:
    std::string name;
    int damage;

public:
    Weapon(std::string name, int damage);
    std::string GetName() const;
    int GetDamage() const;
};