#include "agent.hpp"

namespace smarthome
{

Controller::Controller()
: 
{}

void Controller::getEvent(Event a_event)
{
    std::lock_guard guard(m_mutex);
    //check location of event due to time stamp
    auto toInsert = m_relevantEvents.end();
    for (auto& e : m_relevantEvents)
    {
        if (e.time() > a_event.time())
        {
            toInsert = e;
            break;
        }
    }
    m_relevantEvents.insert(toInsert, a_event);
}

void Controller::connect(EventRouter& a_router)
{
    a_router.addController(*this);
}

void Controller::react()
{
    std::unique_lock<std::mutex>(m_mutex) lock;
    std::condition_variable cond(lock, []{ return !m_relevantEvents.size() == 0});
    cond.wait()
    doSomethingWith(m_relevantEvents[0]);
    m_relevantEvents.pop_front();
}

void Controller::run()
{
    while(true) //m_stop member
    {
        react();
    }
}

} //namespace smarthome
