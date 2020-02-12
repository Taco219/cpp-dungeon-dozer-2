#pragma once

#include "iMob.hpp"
#include "inventory.hpp"

class Player : public IMob
{
private:
    std::string name;
    int health;
    Inventory inventory;

public:
    Player(std::string name, int health, Inventory Inventory);
    ~Player() = default;

    std::string GetName() const override;
    int GetHealth() const override;
    int GetAttack() const override;

    void RecieveDamage(int damage) override;
};