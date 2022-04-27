#pragma once

#include <vector>
#include "room.hpp"
#include "device.hpp"

namespace smarthome
{

class Building
{
public:
    static Building& makeBuilding(std::ifstream& a_configuration);
    void addSensor(Location, Type);
    void addDevice(Location, Type);

private:
    Building(); 

private:
    std::vector<std::vector<size_t>> m_floors; //size of vector == num of floors, every item is vector of rooms on the floor
    std::unorderd_map<Location, RoomController> m_rooms;
//    std::vector<std::shared_ptr<Device>> m_devices;
    std::vector<Sensor> m_sensors;
};

} //namespace smarthome
