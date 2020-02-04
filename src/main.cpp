#include "console.hpp"
#include "game.hpp"

#include <iostream>

int main()
{
    EventGenerator *evg = new EventGenerator();

    Console *console = new Console(*evg);

    Game g = Game(*console, *evg);
    g.Run();

    delete console;
    console = nullptr;
}