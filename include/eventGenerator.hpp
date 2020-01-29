#pragma once

#include "events.hpp"

#include <vector>

class EventGenerator
{
private:
    std::vector<Event> events;

public:
    EventGenerator();

    void PushEvent(Event event);
    Event GetEvent();
};