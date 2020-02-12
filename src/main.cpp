#include "console.hpp"
#include "game.hpp"

#include <iostream>

#include <chrono>
#include <thread>

Player *CreatePlayer()
{
    Inventory inv;

    Armour arm = Armour("T-shirt", 5);
    inv.AddArmour(arm);

    Weapon wep = Weapon("Dull sword", 10);
    inv.AddWeapon(wep);

    Player *player = new Player("Taco", 100, inv);
    return player;
}

int main()
{
    EventGenerator *evg = new EventGenerator();
    Console *console = new Console(*evg);

    Player *player = CreatePlayer();

    Game g = Game(*console, *evg, *player);
    g.Run();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    delete player;
    player = nullptr;
    delete console;
    console = nullptr;
    delete evg;
    evg = nullptr;
}