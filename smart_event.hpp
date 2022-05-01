#include <string>
#include <ctime>
#ifndef EVENT_HPP
#define EVENT_HPP

namespace iot{

class Event{
public:
        Event();
        ~Event();

protected:
        time_t getTime() const;
        std::string getLocation() const;
        time_t m_when;
        std::string m_where; // class Location??
        bool isHappening() const;

private:
        Event &operator=(Event const &a_orig); // no implementation
        Event(Event const &a_orig);            // no implementation
};

    // how to put into log?

class Temperature : public Event{
public:
        Temperature(std::string a_where, float a_temp);
        float getTemp() const;

private:
    double m_content;
    std::string m_where;
    time_t m_when;
};

// create rand temp simulator;

class Fire : public Event{
public:
    Fire(std::string a_where);
    bool isHappening() const;

private:
    bool m_content;
    std::string m_where;
    time_t m_when;
};

class Smoke : public Event{
public:
    Smoke(std::string a_where);
    bool isHappening() const;

private:
    bool m_content;
    std::string m_where;
    time_t m_when;
};

    // sensor creates event.
    // sensor:
    // knows its location,
    // knows what event type it measures,
    //
class Movement : public Event{
public:
    Movement(std::string a_where);
    bool isHappening() const;

private:
    bool m_content;
    std::string m_where;
    time_t m_when;
};

    // class EventMap{ //KNOWS BUILDING - can go to certain location in building
    //     //a map of key: event, value: func
    //     //key: fire, // value: extinguish(event.m_location) >>> how is this done?? predicate function??
    // };

    // eventMap[event.m_eventType](event.m_location);

    // class EventHandler{
    // public:
    //     void handle(Event m_event);
    // private:
    //     //container m_events
    // };

    // A smart home controller, smart home hub, or home automation controller is the brain behind your smart home. It is the device that controls all your smart appliances and devices. These can range anywhere from lightbulbs to music systems, electronic blinds, TVs, doorbells, thermostats, security systems and so much more.

    // fire event - turn to sparkAlexa? she can find the specific fire extinguisher by location?

} // namespace iot
#endif // EVENT_HPP
