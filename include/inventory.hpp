#pragma once

#include <vector>

#include "armour.hpp"
#include "weapon.hpp"

class Inventory
{
private:
    std::vector<Weapon> weapons;
    std::vector<Armour> armours;

public:
    void AddWeapon(Weapon &weapon);
    void AddArmour(Armour &armour);

    int GetTotalDamage() const;
    int GetTotalDefence() const;
};