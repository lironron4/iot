#include "smart_home_server.hpp"

namespace smarthome
{

Server::Server (std::ifstream& a_configuration, size_t a_threads)
{
    m_threads.reserve(a_threads);
    parseFile(a_configuration);
}

void Server::parseFile (std::ifstream& a_configuration)
{
    std::vector<std::string> deviceDetails;
    deviceDetails.reserve(6);

    while(!a_configuration.eof())
    {  
        for (size_t i = 0; i< 6; ++i)
        {
            std::getline(a_configuration, deviceDetails[i], '\n');
            size_t index = deviceDetails[i].find("=", 0);
            deviceDetails[i].erase(0, index+1);
        }
        m_controllers.push_back(new Controller(deviceDetails)); //should be shared ptr
    }
}

/*
        >id, type, room, floor, log, config;

        std::getline(a_configuration, id, '\n');
        std::getline(a_configuration, type, '\n');
        std::getline(a_configuration, room, '\n');
        std::getline(a_configuration, floor, '\n');
        std::getline(a_configuration, log, '\n');
        std::getline(a_configuration, config, '\n');

        size_t index = id.find("=", 0);
        id.erase(0, index+1);
*/       


void Server::run ()
{   
    //sensor should be on...
    size_t threadsToGetFromSensor = m_numOfThreads/2; //maybe less
    for(size_t i=0; i< threadsToGetFromSensor; ++i)
    {
        threads[i] = std::thread(&Sensor::run, m_sensors);
        //for now every thread get one sensor to take care for
    }

    for(size_t i=threadsToGetFromSensor; i< m_numOfThreads - threadsToGetFromSensor; ++i)
    {
        threads[i] = std::thread(&EventRouter::run, m_server);
    }

    m_router.run();

    //get events from queue
    while (true)
    {
        
        if (!m_eventsQueue.isEmpty())
        {
            m_router.
        }
    }
}

} //namespace smarthome
