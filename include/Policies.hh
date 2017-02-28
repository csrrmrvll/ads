#ifndef POLICIES_HH_INCLUDED
#define POLICIES_HH_INCLUDED

namespace csr
{
    template<typename T> struct new_creator
    {
        T* operator()() { return new T; }
    };
}

#endif // POLICIES_HH_INCLUDED
