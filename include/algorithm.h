#ifndef ADS_ALGORITHM_H
#define ADS_ALGORITHM_H

#include <algorithm>
#include <iterator>

#ifdef _MSC_VER
#define NOMINMAX
#endif

namespace ads
{
    template<typename Container,typename UnaryPredicate>
    bool allOf(const Container & c, UnaryPredicate p)
    {
        return std::all_of(begin(c),end(c),p);
    }

    template<typename Container,typename UnaryPredicate>
    bool anyOf(const Container & c, UnaryPredicate p)
    {
        return std::any_of(begin(c),end(c),p);
    }

    template<typename Container,typename UnaryPredicate>
    bool noneOf(const Container & c, UnaryPredicate p )
    {
        return std::none_of(begin(c),end(c),p);
    }

    template<typename Container,typename UnaryFunction> inline
    UnaryFunction forEach(const Container & c, UnaryFunction f)
    {
        return std::for_each(begin(c),end(c),f);
    }

    template<typename Container>
    typename std::iterator_traits<typename Container::const_iterator>::difference_type
    count(const Container & c, const typename Container::value_type & v)
    {
        return std::count(begin(c),end(c),v);
    }

    template<typename Container,typename UnaryPredicate>
    typename std::iterator_traits<typename Container::const_iterator>::difference_type
    countIf(const Container & c, UnaryPredicate p)
    {
        return std::count_if(begin(c),end(c),p);
    }

    template<typename Container>
    std::pair<typename Container::const_iterator,bool> find(const Container & c, const typename Container::value_type & v)
    {
        auto    last = end(c),
                pos = std::find(begin(c),last,v);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<typename Container,typename UnaryPredicate>
    std::pair<typename Container::const_iterator,bool> findIf(const Container & c, UnaryPredicate p)
    {
        auto    last = end(c),
                pos = std::find_if(begin(c),last,p);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<typename Container,typename UnaryPredicate>
    std::pair<typename Container::const_iterator,bool> findIfNot(const Container & c, UnaryPredicate p)
    {
        auto    last = end(c),
                pos = std::find_if_not(begin(c),last,p);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<typename T>
    bool swapIf(T & x, T & y, bool b)
    {
        if (b == false)
        {
            return false;
        }
        std::swap(x,y);
        return true;
    }

    template<typename T,typename BinaryPredicate>
    bool swapIf(T & x, T & y, BinaryPredicate p)
    {
        if (p(x,y) == false) // overloaded operator()
        {
            return false;
        }
        std::swap(x,y);
        return true;
    }
}

#endif // ADS_ALGORITHM_H