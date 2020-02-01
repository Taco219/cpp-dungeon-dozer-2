#pragma once

#include <string>

class IMob
{
public:
    virtual ~IMob() = default;

    virtual std::string GetName() const = 0;
    virtual int GetHealth() const = 0;
    virtual int GetAttack() const = 0;

    virtual void RecieveDamage(int damage) = 0;
};