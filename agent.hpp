#pragma once

#include <list>
#include "event_router.hpp"
#include "location.hpp"
#include "event_types.hpp"

namespace iot
{

enum class Range
{
    LOCAL,
    FLOOR,
    BUILDING
};

class Controller //abstract
{
public:
    Controller();
//    Controller(std::vector<std::string> a_arguments);
    virtual ~Controller(){}
    virtual void getEvent(Event a_event);
    virtual void connect (EventRouter const& a_router); //register
    virtual void run();
    virtual void react();

//    std::string id() const;
//    std::string type() const;
//    Location location() const;

    using EventType = std::string;

protected:
    void sendEvent();
    void registerToType(EventType, Location);        
    virtual void doSomethingWith(Event a_event) = 0;

protected:
//    std::string m_deviceID;
//    std::string m_type;
//    Location m_location;
//    std::vector<std::pair<EventType, Range>> m_registerToEvents;
    std::list<Event*> m_relevantEvents; //should be heap?
    std::mutex m_mutex; //or blocking container?
};

} //namespace smarthome
