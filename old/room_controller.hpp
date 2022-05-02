#pragma once

#include <vector>
#include <memory>

namespace smarthome
{

class RoomController
{
public:
    RoomController(); //open "server"/real server
    Task getTask(); //get task from server
    sendTaskToDevice();
    void addDevice(DeviceType a_type); //connect to controller

private:
    Location m_location;
    std::unordered_map<DeviceType/ID> m_devices;    //<std::shared_ptr<Device>> m_devices;
    
};

} //namespace smarthome
