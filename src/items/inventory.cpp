#include <inventory.hpp>

void Inventory::AddWeapon(Weapon &weapon)
{
    weapons.push_back(weapon);
}

void Inventory::AddArmour(Armour &armour)
{
    armours.push_back(armour);
}

int Inventory::GetTotalDamage() const
{
    int totalDamage = 0;
    for (const Weapon &weapon : weapons)
    {
        totalDamage += weapon.GetDamage();
    }
    return totalDamage;
}

int Inventory::GetTotalDefence() const
{
    int totalDefence = 0;
    for (const Armour &armour : armours)
    {
        totalDefence += armour.GetDefence();
    }
    return totalDefence;
}
