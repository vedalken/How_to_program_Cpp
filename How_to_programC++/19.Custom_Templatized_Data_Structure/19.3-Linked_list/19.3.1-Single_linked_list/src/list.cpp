#include "list.h"

template <typename NODETYPE>
std::ostream& operator<<(std::ostream&         out,
                         const List<NODETYPE>& a_list)
{
    std::copy(a_list.cbegin(), a_list.cend(),
              std::ostream_iterator<NODETYPE>(out, " "));
    return out;
}

template <>
std::ostream& operator<<(std::ostream&     out,
                         const List<char>& a_list)
{
    std::copy(a_list.cbegin(), a_list.cend(),
              std::ostream_iterator<char>(out, ""));
    return out;
}
