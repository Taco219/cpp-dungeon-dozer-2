#pragma once

#include "console.hpp"
#include "eventGenerator.hpp"
#include "sdFight.hpp"

class Game
{
private:
    Console &console;
    EventGenerator &eventGenerator;
    SdFight *fight;
    bool isPlaying;

public:
    Game(Console &console, EventGenerator &EventGenerator);
    ~Game();
    void Run();
};