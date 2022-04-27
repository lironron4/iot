#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <vector>
#include <time.h>
#include <string>

class Sensor{
public:
    Sensor();
    virtual int measure(); // = 0?!
    virtual void sendCurrent(); //parameter(s)??

    //event - is it a state where 
// private:
//     int m_measurement;
       // int m_socket;
};

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