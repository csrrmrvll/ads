#ifndef CTCHECK_HH_INCLUDED
#define CTCHECK_HH_INCLUDED

namespace csr
{
    // declaration provided in order to get a compile time error
    // when instantiated with false
    template<bool> struct ctcheck;

    template<> struct ctcheck<true> {}; // the only specialization needed
}

#endif // CTCHECK_HH_INCLUDED
