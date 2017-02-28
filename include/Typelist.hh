#ifndef TYPELIST_HH_INCLUDED
#define TYPELIST_HH_INCLUDED

#include "Type_manip.hh"
#include "Void_t.hh"

namespace csr
{
    template<typename... Args>
    struct typelist;
    template<typename Head,typename ...Tail>
    struct typelist<Head,Tail...>
    {
        typedef Head head;
        typedef typelist<Tail...> tail;
    };
// specialization needed to stop recursion
    template<> struct typelist<> // default void_t params list
    {
        typedef void_t head;
        typedef void_t tail;
    };
}

#endif // TYPELIST_HH_INCLUDED
