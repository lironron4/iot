#pragma once

#include <mutex>
#include <vector>

namespace iot{

template <typename T>
class ThreadSafeVector
{
public:
    ThreadSafeVector();
    void get(T& a_data, size_t index) const;
    void set(T const& a_key, size_t index);
    void push_back(T const& a_key);
    void pop_back();

    size_t size() const;

private:
    ThreadSafeVector(ThreadSafeVector const& a_source); //can't copy Mutex - no imple
    ThreadSafeVector& operator=(ThreadSafeVector const& a_source); //can't copy Mutex - no imple

private:
    std::vector<T> m_data;
    mutable std::mutex m_mtx;
};

#include "thread_safe_vector.hxx"

} //namespace iot