#pragma once

#include "iMob.hpp"

class Player : public IMob
{
private:
    std::string name;
    int health;
    int attack;

public:
    Player(std::string name, int health, int attack);
    ~Player() = default;

    std::string GetName() const override;
    int GetHealth() const override;
    int GetAttack() const override;

    void RecieveDamage(int damage) override;
};