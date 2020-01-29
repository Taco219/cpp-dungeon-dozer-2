#include <iostream>

#include "game.hpp"

int main()
{
    std::cout << "Hallo dungeion 2" << std::endl;
    EventGenerator evg = EventGenerator();
    SdFight fight;

    Game g = Game(evg, fight);
    g.Run();
}