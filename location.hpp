#pragma once

//#include "building_map.hpp" //how I know the valid values for location?

namespace smarthome
{

class Location
{
public:
    Location(std::string const& a_floor, std::string const& a_roomNumber);
    std::string floor() const;
    std::string room() const;
    bool operator==(Location const& a_other);

private:
    std::string m_floor;
    std::string m_room;
};

} //namespace smarthome