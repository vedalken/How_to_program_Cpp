/*
 * Implementation of threadsafe queue.
 */
#ifndef THREADSAFE_QUEUE_H
#define THREADSAFE_QUEUE_H

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template <typename T>
class threadsafe_queue
{
public:
    /*
     * Default constructor
     */
    threadsafe_queue()
        : m_data()
    {
    }

    /*
     * Copy constructor
     */
    threadsafe_queue(const threadsafe_queue& a_other)
    {
        std::lock_guard<std::mutex> l(m_mutex);
        m_data = a_other.m_data;
    }

    /*
     * Copy assignment operator
     */
    const threadsafe_queue& operator=(const threadsafe_queue& a_other)
    {
        std::lock_guard<std::mutex> l(m_mutex);
        if (this != &a_other) {
            m_data = a_other.m_data;
        }
        return this;
    }

    /*
     * Move and assignment operator (disabled)
     */
    threadsafe_queue(threadsafe_queue&& a_other) = delete;
    threadsafe_queue& operator=(threadsafe_queue&& a_other) = delete;

    /*
     * Function: push
     * ----------------------
     * Push data onto thread safe queue.
     */
    void push(T a_data)
    {
        std::lock_guard<std::mutex> l(m_mutex);
        m_data.push(a_data);
        m_con.notify_one();
    }

    /*
     * Function: wait_and_pop
     * ----------------------
     * Wait and pop data from thread safe queue.
     */
    void wait_and_pop(T& a_data)
    {
        std::unique_lock<std::mutex> l(m_mutex);
        m_con.wait(l, [this] { return !m_data.empty(); });
        a_data = m_data.front();
        m_data.pop();
    }

    /*
     * Function: wait_and_pop
     * ----------------------
     * Wait and pop data from thread safe queue.
     */
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_ptr<std::mutex> l(m_mutex);
        m_con.wait(l, [this] { return !m_data.empty(); });
        std::shared_ptr<T> data = std::make_shared<T>(m_data.front());
        m_data.pop();
        return data;
    }

    /*
     * Function: try_pop
     * -----------------
     * Pop data from thread safe queue without waiting. On failure 
     * return false, otherwise true.
     */
    bool try_pop(T& a_data)
    {
        std::lock_guard<std::mutex> l(m_mutex);
        if (m_data.empty())
            return false;

        a_data = m_data.front();
        m_data.pop();
        return true;
    }

    /*
     * Function: try_pop
     * -----------------
     * Pop data from thread safe queue without waiting. On failure 
     * return empty shared pointer, otherwise shared pointer to
     * popped data.
     */
    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> l(m_mutex);
        if (m_data.empty()) {
            return std::shared_ptr<T>();
        }
        std::shared_ptr<T> data = std::make_shared<T>(m_data.front());
        m_data.pop();
        return data;
    }

    /*
     * Function: is_empty
     * ------------------
     * Check if queue is empty.
     */
    bool is_empty() const
    {
        std::lock_guard<std::mutex> l(m_mutex);
        return m_data.empty();
    }

private:
    std::queue<T> m_data;
    std::condition_variable<T> m_con;
    const std::mutex m_mutex; 
};

#endif
