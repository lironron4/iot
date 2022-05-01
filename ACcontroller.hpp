#pragma once

#include <vector>
#include "agent.hpp"
#include "event_types.hpp"
#include "smart_event.hpp"

namespace iot
{

class ACcontroller : public Controller
{
public:
    ACcontroller(std::vector<std::string> a_arguments);
    virtual void doSomethingWith(Event a_event);

private:
    void takeCare(Temperature& a_event);
    void takeCare(Fire& a_event);
    void off();
    void raiseTemperature();
    void reduceTemperature();

private:
};

} //namespace iot
