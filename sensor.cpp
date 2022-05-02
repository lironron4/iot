#include <memory>
#include <ctime>
#include <string>
#include <unistd.h>
#include "../inc/sensor.hpp"


//or, divide into class BooleanSensor / class MeasurementSensor

namespace iot{

int WAIT = 1;

float generateTemp(){
    return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(159.9))) - 89.2;
}

// uint generateBool(){
//     return rand() % 2;
// }


Sensor::Sensor(){} //automatic measurement upon creation so m_latest is not empty?

Sensor::~Sensor(){}


TempSensor::TempSensor(std::string a_location)
: m_latest(generateTemp())
, m_location(a_location)
{
    //send already at setup?
}


void TempSensor::run(mt::BlockingQueue<std::shared_ptr<Event>> a_q){ //temporary parameter, TODO: socket + send from inside function body
    while(true){   
        a_q.enqueue(std::shared_ptr<Event> (new Temperature(m_location, generateTemp())));
    }
}


MovementDetector::MovementDetector(std::string a_location)
: m_latest(true) 
, m_location(a_location)
{}


void MovementDetector::run(mt::BlockingQueue<std::shared_ptr<Event>> a_q){ //temporary parameter, TODO: socket + send from inside function body
    while(true){
        if(rand() % 2){
            a_q.enqueue(std::shared_ptr<Event> (new Movement(m_location)));
        }
        sleep(WAIT);
    }

}


SmokeDetector::SmokeDetector(std::string a_location)
: m_latest(true)
, m_location(a_location)
{}


void SmokeDetector::run(mt::BlockingQueue<std::shared_ptr<Event>> a_q){ //temporary parameter, TODO: socket + send from inside function body
    while(true){
        if(rand() % 2){
            a_q.enqueue(std::shared_ptr<Event> (new Smoke(m_location)));
        }
    }

}

FireDetector::FireDetector(std::string a_location)
: m_latest(true)
, m_location(a_location)
{}


void FireDetector::run(mt::BlockingQueue<std::shared_ptr<Event>> a_q){ //temporary parameter, TODO: socket + send from inside function body
    while(true){
        if(rand() % 2){
            a_q.enqueue(std::shared_ptr<Event> (new Fire(m_location)));
        }
    }
}

}//namespace iot
