#ifndef RANGE_H
#define RANGE_H

#include <utility>

namespace ads
{
    template<typename Iterator>
    class range
    :   private std::pair<Iterator,Iterator>
    {
        using base = std::pair<Iterator,Iterator>;
    public:
        using iterator = Iterator;
        range(Iterator first, Iterator last)
        :   base{first,last}
        {
        }

        range(const std::pair<Iterator,Iterator> & p)
        :   base{p}
        {
        }

        range(std::pair<Iterator,Iterator> && p)
        :   base{p}
        {
        }

        iterator begin() const { return this->first; }
        iterator end() const { return this->second; }
    };

    template<typename Iterator>
    range<Iterator> make_range(Iterator first, Iterator last)
    {
        return range<Iterator>(first, last);
    }

    template<typename Iterator>
    range<Iterator> make_range(std::pair<Iterator,Iterator> && p)
    {
        return range<Iterator>(p);
    }
}

#endif // RANGE_H
