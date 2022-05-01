#include "location.hpp"

Location::Location(std::string const& a_floor, std::string const& a_roomNumber)
: m_floor (a_floor)
, m_room (a_room)
{}

std::string Location::floor() const
{
    return m_floor;
}

std::string Location::room() const
{
    return m_room;
}

bool Location::operator==(Location const& a_other)
{
    return (m_floor == a_other.floor() && m_room == a_other.room());
}
