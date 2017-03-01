#ifndef RANGE_H
#define RANGE_H

#include <iterator>
#include <utility>

namespace ads
{
    template<typename T>
    using range_pair = std::pair<T,T>;

    template<typename Iterator>
    class range
    :   private range_pair<Iterator>
    {
        using base = range_pair<Iterator>;
    public:
        using iterator = Iterator;
        using value_type = typename std::iterator_traits<iterator>::value_type;
        using base::base;

        iterator begin() const { return this->first; }
        iterator end() const { return this->second; }
    };

    template<typename Iterator>
    range<Iterator> make_range(Iterator first, Iterator last)
    {
        return range<Iterator>(first, last);
    }

    range<std::vector<int>::const_iterator> make_range(int first, int last)
    {
        using Ivector = std::vector<int>;
        typename Ivector::size_type size = last - first + 1;
        Ivector v(size);
        std::iota(begin(v),end(v),first);
        return range<Ivector::const_iterator>(begin(v),end(v));
    }

    template<typename Container>
    range<typename Container::const_iterator> make_range(const Container & c)
    {
        return range<typename Container::const_iterator>(begin(c),end(c));
    }

    template<typename Container>
    range<typename Container::iterator> make_range(range_pair<typename Container::const_iterator> && p)
    {
        return range<Container>(p);
    }
}

#endif // RANGE_H
