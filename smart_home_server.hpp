#pragma once

#include <unordered_map>
#include <vector>
#include <thread>

namespace smarthome
{

class Server
{
public:
    Server (std::ifstream& a_configuration, size_t a_threads);
    void run();

private:
    void parseFile(std::ifstream& a_configuration);

private:
    std::vector<Sensor> m_sensors;
    std::vector<Controller> m_controllers;
    EventRouter m_router;
    mt::BlockingQueue<Event> m_eventsQueue; //should be another type? protection qeueu..
    size_t m_numOfThreads;
    std::vector<std::thread> m_threads;
};

} //namespace smarthome