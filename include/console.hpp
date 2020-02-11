#pragma once

#include "eventGenerator.hpp"
#include "iMob.hpp"

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
    bool isRunning;

    void PrintLine(std::string line);
    void StartPrinting();
    void AddToPrintQue(std::string lineToPrint);
    void WaitForConsole();

    std::string ReadLine();
    u_int ReadLineInt();
    u_int ReadLineInt(u_int maxValue);
    void PrintInvalidInput();

public:
    Console(EventGenerator &EventGenerator);
    virtual ~Console();

    void FgthStart(const std::string &playerName, const std::string &monsterName);
    void FgthPickPlayerAction();

    void FgthMobAttack(const IMob &attacker, const IMob &reciever);
    void FgthMobDied(const IMob &mob);
    void FgthMobFled(const IMob &mob);

    void FgthPlayerPickAction();
};