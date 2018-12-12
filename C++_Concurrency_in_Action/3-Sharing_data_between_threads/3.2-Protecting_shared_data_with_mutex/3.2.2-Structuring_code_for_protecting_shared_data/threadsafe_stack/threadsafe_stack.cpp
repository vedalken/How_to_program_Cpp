#include <iostream>
#include <stack>
#include <memory>
#include <mutex>
#include <exception>
#include <thread>
#include <type_traits>

template <typename T>
class threadsafe_stack
{
public:
    threadsafe_stack() {}
    threadsafe_stack(const threadsafe_stack& a_other)
    {
        std::lock_guard<std::mutex> lock(a_other.m_mutex);
        m_data = a_other.m_data;
    }

    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_data.push(new_value);
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_data.empty()) {
            throw std::exception();           
        }

        auto data = std::make_shared<T>(m_data.top());
        m_data.pop();
        return data;
    }

    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_data.empty()) {
            throw std::exception();
        }

        value = m_data.top();
        m_data.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_data.empty();
    }

    void operator()()
    {
        push(T());
        pop();
    }

private:
    std::stack<T>      m_data;
    mutable std::mutex m_mutex;
};

int main()
{
    threadsafe_stack<int> tss_int;
    std::thread t(std::ref(tss_int));
    t.join();

    return 0;
}
