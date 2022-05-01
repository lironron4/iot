#pragma once

#include <unordered_map>
#include "event_types.hpp"
#include "agent.hpp"
#include "ACcontroller.hpp"
#include "../../inc/blocking_queue.hpp"
#include "location.hpp"
#include "thread_safe_vector.hpp"
#include "smart_event.hpp"

namespace smarthome
{

class EventRouter
{
public:
    using EventType = std::string; //can be enum

    EventRouter(mt::BlockingQueue<std::shared_ptr<iot::Event>>& a_queue);
    void run();

    addController(iot::ACcontroller& a_controller);

private:
    //mutex for map also?
    std::unordered_map<std::string, std::unordered_map<Location, iot::ThreadSafeVector<std::shared_ptr<iot::ACcontroller>>> m_groups; ////// 
    mt::BlockingQueue<std::shared_ptr<iot::Event>>& m_eventsQueue;
};


} //namespace smarthome
