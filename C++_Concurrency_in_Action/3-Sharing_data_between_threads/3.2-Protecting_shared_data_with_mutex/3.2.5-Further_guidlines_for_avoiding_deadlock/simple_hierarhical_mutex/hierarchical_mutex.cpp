#include <limits>
#include <stdexcept>
#include "hierarchical_mutex.h"

thread_local unsigned long hierarchical_mutex::m_this_thread_hierarchy_value = 
    std::numeric_limits<unsigned long>::max();

hierarchical_mutex::hierarchical_mutex(unsigned long a_value)
    : m_hierarchy_value(a_value),
      m_previous_hierarchy_value(0)
{
}

void hierarchical_mutex::check_for_hierarchy_violation()
{
    if (m_this_thread_hierarchy_value <= m_hierarchy_value)
    {
        throw std::logic_error("mutex hierarchy violated");
    }
}

void hierarchical_mutex::update_hierarchy_value()
{
    m_previous_hierarchy_value = m_this_thread_hierarchy_value;
    m_this_thread_hierarchy_value = m_hierarchy_value;
}

void hierarchical_mutex::lock()
{
    check_for_hierarchy_violation();
    m_mutex.lock();
    update_hierarchy_value();
}

void hierarchical_mutex::unlock()
{
    m_this_thread_hierarchy_value = m_previous_hierarchy_value;
    m_mutex.unlock();
}

bool hierarchical_mutex::try_lock()
{
    check_for_hierarchy_violation();
    if (!m_mutex.try_lock())
        return false;
    update_hierarchy_value();
    return true;
}
