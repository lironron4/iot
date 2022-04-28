


//created by sensor
//server gets buffer with event in it - turned back into event class

class Event {
public:
    Event();
    ~Event();
protected:
    time_t m_timeStamp;
    std::string m_eventType;
    std::string m_location; //class Location??
//private:
    //cctor ?
    //operator= ?
};

//how to put into log? 


class Temperature : public Event{
public:
    Temperature(double a_detection, bool isRising);
private:
    double m_currTemp;
}; 

//create rand temp simulator; 

class Fire : public Event{
public:
    Fire();
}; 

class Smoke : public Event{
public:
    Smoke();
}; 


class Movement : public Event{
public:
    Movement();
}; 

// class EventMap{ //KNOWS BUILDING - can go to certain location in building
//     //a map of key: event, value: func
//     //key: fire, // value: extinguish(event.m_location) >>> how is this done?? predicate function??
// };

//eventMap[event.m_eventType](event.m_location);



// class EventHandler{
// public: 
//     void handle(Event m_event);
// private:
//     //container m_events
// };

//A smart home controller, smart home hub, or home automation controller is the brain behind your smart home. It is the device that controls all your smart appliances and devices. These can range anywhere from lightbulbs to music systems, electronic blinds, TVs, doorbells, thermostats, security systems and so much more.


//fire event - turn to sparkAlexa? she can find the specific fire extinguisher by location?

