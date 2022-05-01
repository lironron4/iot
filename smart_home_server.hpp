#pragma once

#include <unordered_map>
#include <vector>
#include <thread>
#include "agent.hpp"
#include "thread_safe_vector.hpp"
#include "../../inc/blocking_queue.hpp"

namespace smarthome
{

class Server
{
public:
    Server (std::ifstream& a_configuration);
    void run();

private:
    void parseFile(std::ifstream& a_configuration);

private:
//    std::vector<Sensor> m_sensors;
    iot::ThreadSafeVector<std::shared_ptr<iot::Controller>> m_controllers;
    EventRouter m_router;
    mt::BlockingQueue<std::shared_ptr<iot::Event>> m_eventsQueue; //should be another type? protection qeueu..    
    size_t m_numOfThreads;
    std::vector<std::thread> m_threads;
};

} //namespace smarthome