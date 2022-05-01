#include <string>
#include <ctime>
#include "../inc/smart_event.hpp"

namespace iot
{


Event::Event(){}

Event::~Event(){}


time_t Event::getTime() const{
    return m_when;
}

std::string Event::getLocation() const{
    return m_where;
}



Temperature::Temperature(std::string a_where, float a_temp)
: m_content(a_temp)
, m_where(a_where)
{
    std::time_t m_when = std::time(0);   // get time now
    std::localtime(&m_when);
}

float Temperature::getTemp() const{
    return m_content;
}



Movement::Movement(std::string a_where)
: m_content(true)
, m_where(a_where)
{
    std::time_t m_when = std::time(0);   // get time now
    std::localtime(&m_when);
}

bool Movement::isHappening() const{
    return m_content;
}



Smoke::Smoke(std::string a_where)
: m_content(true)
, m_where(a_where)
{
    std::time_t m_when = std::time(0);   // get time now
    std::localtime(&m_when);
}

bool Smoke::isHappening() const{
    return m_content;
}



Fire::Fire(std::string a_where)
: m_content(true)
, m_where(a_where)
{
    std::time_t m_when = std::time(0);   // get time now
    std::localtime(&m_when);
}

bool Fire::isHappening() const{
    return m_content;
}



} // namespace iot
