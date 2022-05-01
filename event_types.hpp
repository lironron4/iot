#pragma once 

namespace smarthome
{

enum class EventType
{
   Fire,
   Smoke,
   Temperture,
   Movement 
};

/*
class EventType
{
public:    
    EventType();
    void addType(std::string a_type);
    auto begin();
    auto end();

private:
    std::unordered_set<std::string>
};
*/
} //namespace smarthome
