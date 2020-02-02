#include "console.hpp"

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