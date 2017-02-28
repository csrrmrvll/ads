#ifndef SELECT_HH_INCLUDED
#define SELECT_HH_INCLUDED

#include "Null.hh"

namespace csr
{
    template<bool flag,typename A,typename B>
    struct select
    {
        typedef A result;
    };

    template<typename A,typename B>
    struct select<false,A,B>
    {
        typedef B result;
    };
}

#endif // SELECT_HH_INCLUDED
