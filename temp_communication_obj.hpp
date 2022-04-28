#pragma once

#include "event.hpp"
#include "blocking_queue.hpp"

namespace smarthome
{

class MoveToQueue
{
public:
    MoveToQueue(BlockingQueue<Event>& a_queue);
    void send(Event& a_event);

private:
    BlockingQueue<Event>& m_queue;    
};

inline MoveToQueue::MoveToQueue(BlockingQueue& a_queue)
: m_queue (a_queue)
{}

inline void MoveToQueue::send(Event a_event)
{
    m_queue.enqueue(a_event);
}

} //namespace smarthome
