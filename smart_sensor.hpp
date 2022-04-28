#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <vector>
#include <time.h>
#include <string>

template <typename T>
class Sensor{
public:
    Sensor(T& a_communicationObject);
    virtual int measure(); // = 0?!
    virtual void sendCurrent(Event&); //parameter(s)??

    //event - is it a state where 
// private:
//     int m_measurement;
       // int m_socket;
protected:
    Location m_location;
    std::string m_type; //string or enum?
    T& m_communicationObject;
};

template <typename T>
void Sensor::sendCurrent(Event& a_event)
{
    m_communicationObject.send(a_event);
}

class TempSensor : public Sensor {
public:
    int measure();
    void sendCurrent(); //parameter(s)??
private:
    int m_currTemp;
};

class MovementDetector : public Sensor {
public:
    int measure();
    void sendCurrent(); //parameter(s)??
private:
    int m_currTemp;
};

    //protection queue for events?
    //min heap - complexity
    //check if fire before even putting it into the queue - if fire >> direct transfer somehow
    //vector<Sensor>



#endif //SENSOR_HPP
