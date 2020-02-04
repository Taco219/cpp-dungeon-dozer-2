#include "console.hpp"

#include <sstream>

Console::Console(EventGenerator &eventGenerator)
    : eventGenerator(eventGenerator)
{
    shouldBePrinting = true;
    thread = std::thread(&Console::StartPrinting, this);
}

void Console::StartPrinting()
{
    while (shouldBePrinting)
    {
        if (linesToPrint.size() > 0)
        {
            std::string line;
            {
                std::lock_guard<std::mutex> guard(vecMutex);
                line = linesToPrint[0];
                linesToPrint.erase(linesToPrint.begin());
            }

            std::lock_guard<std::mutex> guard(cliMutex);
            printf("%s \n", line.c_str());
        }
    }
}

void Console::AddToPrintQue(std::string lineToPrint)
{
    std::lock_guard<std::mutex> guard(vecMutex);
    linesToPrint.push_back(lineToPrint);
}

void Console::PrintHelloWorld()
{
    AddToPrintQue("Hello world!");
}

void Console::Fgth_start(const std::string &playerName, const std::string &monsterName)
{
    std::ostringstream text(std::ostringstream::ate);
    text << playerName << " is fighting " << monsterName << "\n";
    AddToPrintQue(text.str());
}

void Console::Fgth_mobAttack(const IMob &attacker, const IMob &reciever)
{
    std::ostringstream text(std::ostringstream::ate);
    text << attacker.GetName() << " attacked "
         << reciever.GetName() << " for " << attacker.GetAttack() << "\n"
         << reciever.GetName() << " has " << reciever.GetHealth() << " health left.\n";
    AddToPrintQue(text.str());
}
