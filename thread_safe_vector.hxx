
template <typename T>
ThreadSafeVector<T>::ThreadSafeVector(){}

template <typename T>
void ThreadSafeVector<T>::get(T& a_data, size_t index) const
{
    std::lock_guard<std::mutex> guard(m_mtx);
    a_data = m_data[index];
}

template <typename T>
void ThreadSafeVector<T>::set(T const& a_key, size_t index)
{
    std::lock_guard<std::mutex> guard(m_mtx);
    m_data[index] = a_key;
}

template <typename T>
void ThreadSafeVector<T>::push_back(T const& a_key)
{
    std::lock_guard<std::mutex> guard(m_mtx);
    m_data.push_back(a_key);
}

template <typename T>
void ThreadSafeVector<T>::pop_back()
{
    std::lock_guard<std::mutex> guard(m_mtx);
    m_data.pop_back();
}

template <typename T>
size_t ThreadSafeVector<T>::size() const
{
    std::lock_guard<std::mutex> guard(m_mtx);
    return m_data.size();
}
