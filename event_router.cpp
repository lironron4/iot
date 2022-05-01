#include "event_router.hpp"

namespace iot
{

EventRouter::EventRouter(mt::BlockingQueue& a_queue)
m_eventsQueue (a_queue)
{}

void EventRouter::run()
{
    while(true) //member to stop?
    {
        Event* event;
        m_eventsQueue.dequeue(event);
        auto vector = m_groups[event.type()][event.location()];
        for (auto& e : vector)
        {
            e.getEvent(item);
        }
    }
}

void EventRouter::addController(Controller& a_controller)
{
    auto vectorToRegister = a_controller.eventTypes();
    size_t size = vectorToRegister.size();

    for (size_t i = 0; i<size; ++i)
    {
        if (vectorToRegister[i].second == Range::LOCAL)
        {
            m_groups[a_controller.type()][a_controller.location()].push_back(std::shared_ptr<Controller>(&a_controller));
        }
        if (vectorToRegister[i].second == Range::BUILDING)
        {
            for (auto& location : m_groups[a_controller.type()])
            {
                location.second.push_back(a_controller);
            }
        }
        if (vectorToRegister[i].second == Range::FLOOR)
        {
            for (auto& location : m_groups[a_controller.type()])
            {
                if (location.first.floor() == a_controller.floor())
                {
                    location.second.push_back(a_controller);
                }
            }
        }
    }
}


} //namespace iot
