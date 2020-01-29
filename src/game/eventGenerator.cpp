#include "eventGenerator.hpp"

EventGenerator::EventGenerator()
{
}

void EventGenerator::PushEvent(Event event)
{
    events.push_back(event);
}

Event EventGenerator::GetEvent()
{
    Event result = NO_EVENT;

    if (events.size() > 0)
    {
        result = events[0];
        events.erase(events.begin());
    }

    return result;
}
