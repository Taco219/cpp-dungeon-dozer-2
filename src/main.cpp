#include "console.hpp"
#include "game.hpp"

#include <iostream>

int main()
{
    std::cout << "Hallo dungeion 2" << std::endl;
    EventGenerator evg = EventGenerator();
    SdFight fight;

    Console *console = new Console(evg);
    console->PrintHelloWorld();

    Game g = Game(evg, fight);
    g.Run();
}