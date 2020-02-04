#pragma once

#include "iMob.hpp"

class Monster : public IMob
{
private:
    std::string name;
    int health;
    int attack;

public:
    Monster(std::string name, int health, int attack);
    ~Monster() = default;

    std::string GetName() const override;
    int GetHealth() const override;
    int GetAttack() const override;

    void RecieveDamage(int damage) override;
};