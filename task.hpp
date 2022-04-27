#pragma once 

namespace smarthome
{

class Task //abstract
{
public:
    
private:
    DeviceType m_device; //enum
    Location m_location;
    std::function<void(....)> m_task;
};

} //namespace smarthome
