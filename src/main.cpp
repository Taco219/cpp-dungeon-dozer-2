#include "console.hpp"
#include "game.hpp"

#include <iostream>

#include <chrono>
#include <thread>

int main()
{
    EventGenerator *evg = new EventGenerator();
    Console *console = new Console(*evg);

    Game g = Game(*console, *evg);
    g.Run();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    delete console;
    console = nullptr;
    delete evg;
    evg = nullptr;
}