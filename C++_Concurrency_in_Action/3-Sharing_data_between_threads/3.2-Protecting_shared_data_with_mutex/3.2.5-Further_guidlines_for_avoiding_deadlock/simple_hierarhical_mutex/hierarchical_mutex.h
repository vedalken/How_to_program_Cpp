#ifndef HIERARCHICAL_MUTEX
#define HIERARCHICAL_MUTEX

#include <mutex>

class hierarchical_mutex
{
public:
    explicit hierarchical_mutex(unsigned long a_value);
    void lock();
    void unlock();
    bool try_lock();

private:
    std::mutex m_mutex;
    const unsigned long m_hierarchy_value;
    unsigned long m_previous_hierarchy_value;
    static thread_local unsigned long m_this_thread_hierarchy_value;

    void check_for_hierarchy_violation();
    void update_hierarchy_value();
};

#endif
