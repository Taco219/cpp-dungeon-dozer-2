#include "console.hpp"

#include <iostream>
#include <sstream>

Console::Console(EventGenerator &eventGenerator)
    : eventGenerator(eventGenerator)
{
    linesToPrint = std::vector<std::string>();
    isRunning = true;
    thread = std::thread(&Console::StartPrinting, this);
}

Console::~Console()
{
    isRunning = false;
    thread.join();
}

void Console::StartPrinting()
{
    while (isRunning)
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

std::string Console::ReadLine()
{
    if (isRunning)
    {
        std::string str;
        std::lock_guard<std::mutex> guard(cliMutex);
        std::getline(std::cin, str);
        return str;
    }

    throw std::domain_error("Console::ReadLine: isRunning is false should be true.");
}

u_int Console::ReadLineInt()
{
    u_int i = 0;

    while (isRunning && i <= 0)
    {
        try
        {
            std::string line = ReadLine();

            i = std::stoi(line);
            return i;
        }
        catch (std::invalid_argument)
        {
            PrintInvalidInput();
        }
    }

    throw std::domain_error("Console::ReadLineInt: exited while loop without returning value");
}

u_int Console::ReadLineInt(u_int maxValue)
{
    u_int i = 0;
    while (true)
    {
        i = ReadLineInt();

        if (i <= maxValue)
        {
            return i;
        }
        PrintInvalidInput();
    }
}

void Console::PrintInvalidInput()
{
    printf("Invalid input!\n");
}

// public
void Console::FgthStart(const std::string &playerName, const std::string &monsterName)
{
    std::ostringstream text(std::ostringstream::ate);
    text << playerName << " is fighting " << monsterName << "\n";
    AddToPrintQue(text.str());
}

void Console::FgthMobAttack(const IMob &attacker, const IMob &reciever)
{
    std::ostringstream text(std::ostringstream::ate);
    text << attacker.GetName() << " attacked "
         << reciever.GetName() << " for " << attacker.GetAttack() << "\n"
         << reciever.GetName() << " has " << reciever.GetHealth() << " health left.\n";
    AddToPrintQue(text.str());
}

void Console::FgthMobDied(const IMob &mob)
{
    std::ostringstream text(std::ostringstream::ate);
    text << mob.GetName() << " has died.";
    AddToPrintQue(text.str());
}

void Console::FgthPlayerPickAction()
{
    ReadLineInt();
}
