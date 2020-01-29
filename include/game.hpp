#pragma once

#include "eventGenerator.hpp"
#include "sdFight.hpp"

class Game
{
private:
    EventGenerator &eventGenerator;
    SdFight &fight;
    bool isPlaying;

public:
    Game(EventGenerator &EventGenerator, SdFight &fight);
    void Run();
};