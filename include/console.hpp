#pragma once

#include "eventGenerator.hpp"

#include <mutex>
#include <string>
#include <thread>

class Console
{
private:
    EventGenerator &eventGenerator;

    std::mutex cliMutex;
    std::mutex vecMutex;
    std::thread thread;

    std::vector<std::string> linesToPrint;
    bool shouldBePrinting;

    void PrintLine(std::string line);
    void StartPrinting();
    void AddToPrintQue(std::string lineToPrint);

public:
    Console(EventGenerator &EventGenerator);
    virtual ~Console() = default;

    void PrintHelloWorld();
};