#include "ACcontroller.hpp"

namespace iot
{

ACcontroller::ACcontroller(std::vector<std::string> a_arguments)
: m_deviceID(a_arguments[0])
, m_type(a_arguments[1])
, m_location(a_arguments[2], a_arguments[3])
//config & log
{
    m_registerToEvents.push_back(EventType::Fire, Range::FLOOR);
    m_registerToEvents.push_back(EventType::Temperature, Range::LOCAL);
}

virtual void ACcontroller::doSomethingWith(Event a_event)
{        
    takeCare(a_event);
}

void ACcontroller::takeCare(Temperture& a_event)
{
    if (a_event.temperture() < 20.0)
    {
        raiseTemperture();
    }
    if (a_event.temperture() > 25.0)
    {
        reduceTemperture();
    }
}

void ACcontroller::takeCare(Fire& a_event)
{
    off();
}

void ACcontroller::off()
{
    std::cout << "air condition off" << '\n';
}

void ACcontroller::raiseTemperature()
{
    std::cout << "temperature++" << '\n';
}

void ACcontroller::reduceTemperature()
{
    std::cout << "temperature--" << '\n';
}

} //namespace iot