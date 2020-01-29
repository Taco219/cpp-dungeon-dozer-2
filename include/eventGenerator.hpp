#pragma once

#include "events.hpp"

#include <vector>

// todo Threading
class EventGenerator
{
private:
    std::vector<Event> events;

public:
    EventGenerator();

    void PushEvent(Event event);
    Event GetEvent();
};