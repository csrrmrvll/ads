#ifndef NULL_HH_INCLUDED
#define NULL_HH_INCLUDED

namespace csr
{

    template<typename T> struct null
    {
        operator T() { return static_cast<T>(0); }
    };

    template<typename T> struct null<T*>
    {
        operator T*() { return static_cast<T*>(0); }
    };
}

#endif // NULL_HH_INCLUDED
