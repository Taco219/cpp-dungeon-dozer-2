#pragma once

#include <string>

class Armour
{
private:
    std::string name;
    int defence;

public:
    Armour(std::string name, int defence);
    std::string GetName() const;
    int GetDefence() const;
};