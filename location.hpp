#pragma once

#include "building_map.hpp" //how I know the valid values for location?

namespace smarthome
{

class Location
{
public:
    Location(size_t a_floor, size_t a_roomNumber);
    size_t floor() const;
    size_t roomNumber() const;
    Location& operator==(Location const& a_other);

private:
    size_t m_floor;
    size_t m_roomNumber;
};

} //namespace smarthome