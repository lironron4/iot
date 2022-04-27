#pragma once

namespace smarthome
{

//for now it is just map, without devices in rooms. change it.
class BuildingMap
{
public:
    BuildingMap(std::ifstream& a_configuration);

private:
    std::vector<std::vector<size_t>> m_floors; //size of vector == num of floors, every item is vector of rooms on the floor
};

} //namespace smarthome
