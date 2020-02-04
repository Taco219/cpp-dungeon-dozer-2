#include "eventGenerator.hpp"

EventGenerator::EventGenerator()
{
}

void EventGenerator::PushEvent(Event event)
{
    std::lock_guard<std::mutex> guard(mutex);
    events.push_back(event);
}

Event EventGenerator::GetEvent()
{
    Event result = NO_EVENT;

    if (events.size() > 0)
    {
        std::lock_guard<std::mutex> guard(mutex);
        result = events[0];
        events.erase(events.begin());
    }

    return result;
}
