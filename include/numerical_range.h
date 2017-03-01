#ifndef NUMERICAL_RANGE_H
#define NUMERICAL_RANGE_H

#include <vector>
#include "algorithm.h"

namespace ads
{
    template<typename Integral>
    class numerical_range
    :   private std::vector<Integral>
    {
        using base = std::vector<Integral>;
    public:
        using base::iterator;
        using base::value_type;
        using base::begin;
        using base::end;

        numerical_range(Integral first, Integral last)
        :   base(last - first + 1)
        {
            iota(*this,first);
        }
    };

    template<typename Integral>
    numerical_range<Integral> make_numerical_range(Integral first, Integral last)
    {
        return numerical_range<Integral>(first, last);
    }
}

#endif // NUMERICAL_RANGE_H
