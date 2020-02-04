#pragma once

#include "events.hpp"

#include <mutex>
#include <vector>

class EventGenerator
{
private:
    std::mutex mutex;
    std::vector<Event> events;

public:
    EventGenerator();

    void PushEvent(Event event);
    Event GetEvent();
};