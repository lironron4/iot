#ifndef CONTROLLER_AGENT_HPP
#define CONTROLLER_AGENT_HPP

#include <set>
#include <string>
#include "smart_event.hpp"
//?

using namespace std;

namespace iot
{

class ControllerAgent : public Agent
{
public:
   //or std::pair<room, floor> ??
   ControllerAgent(string a_id, string a_type, string a_floor, string a_room, string a_config ); // vector<string> a_vec  
   
   //inside ctor: 
   //according to controller type, choose - 
   //1. eventType to subscribe to; 
   //2. distance of sensors the controller would like to subscribe to from device location; - according to type but also to eventType
   
   virtual ~ControllerAgent() {};
   
    string id() const;
    string eventType() const;
    string floor() const;
    string room() const;
    string config() const;
    
    void getEvent(iot::Event a_event);
    virtual void react(iot::Event a_event);

private:
    string m_id;
    string m_eventType;
    string m_floor;
    string m_room;
    string m_config;
    
    //BlockQueue<Event> m_eventQueue?
};

}// namespace iot
#endif
