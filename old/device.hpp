#pragma once

namespace smarthome
{

class Device //abstract
{
public:
    virtual void on();
    virtual void off();
    virtual int id(); 

protected:
    int m_deviceID;
};

} //namespace smarthome
