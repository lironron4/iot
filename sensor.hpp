#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "../inc/event.hpp"
#include "../inc/blocking_queue.hpp"

namespace iot{
    
class Sensor{
public:
    Sensor(); //automatic measurement upon creation so m_latest is not empty?
    ~Sensor();
    // virtual void measure() = 0;
    virtual void run(mt::BlockingQueue<std::shared_ptr<Event>> a_q) = 0; //temporary parameter, TODO: socket + send from inside function body
private:
    Sensor& operator=(Sensor const& a_orig); // no implementation
    Sensor(Sensor const& a_orig); // no implementation
    
    // int m_socket;

};

class TempSensor : public Sensor {
public:
    TempSensor(std::string a_location);
    void run(mt::BlockingQueue<std::shared_ptr<Event>> a_q); //temporary parameter, TODO: socket + send from inside function body
private:
    float m_latest;
    std::string m_location;
};

class MovementDetector : public Sensor {
public:
    MovementDetector(std::string a_location);
    void run(mt::BlockingQueue<std::shared_ptr<Event>> a_q); //temporary parameter, TODO: socket + send from inside function body
private:
    bool m_latest;
    std::string m_location;
};

class SmokeDetector : public Sensor {
public:
    SmokeDetector(std::string a_location);
    void run(mt::BlockingQueue<std::shared_ptr<Event>> a_q); //temporary parameter, TODO: socket + send from inside function body
private:
    bool m_latest;
    std::string m_location;
};

class FireDetector : public Sensor {
public:
    FireDetector(std::string a_location);
    void run(mt::BlockingQueue<std::shared_ptr<Event>> a_q); //temporary parameter, TODO: socket + send from inside function body
private:
    bool m_latest;
    std::string m_location;
};


    //protection queue for events?
    //min heap - complexity
    //check if fire before even putting it into the queue - if fire >> direct transfer somehow
    //vector<Sensor>

}//namespace iot

#endif //SENSOR_HPP
