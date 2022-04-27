#pragma once

#include "server.hpp"

namespace smarthome
{

class Manager
{
public:
    Manager();
    //get from m_eventsServer an event, send it to m_tasksMap and get the right task
    Task getEvent(); 
    void sendTask(Task a_task, /*location*/);

private:
    Server m_eventsServer;
    Server m_tasksServer;
    TasksMenu m_tasksMap;
};


} //namespace smarthome
