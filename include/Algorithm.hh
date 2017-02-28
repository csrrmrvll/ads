#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include <algorithm>
#include <iterator>

#ifdef _MSC_VER
#define NOMINMAX
#endif

namespace csr
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
    count(const Container & c, UnaryPredicate p)
    {
        return std::count(begin(c),end(c),p);
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
    std::pair<typename Container::const_iterator,bool> find_if(const Container & c, UnaryPredicate p)
    {
        auto    last = end(c),
                pos = std::find_if(begin(c),last,p);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<typename T> inline bool swapIf(T & x, T & y, bool b)
    {
        if (b == false)
        {
            return false;
        }
        std::swap(x,y);
        return true;
    }

    template<class T,typename BinaryPredicate> inline bool swapIf(T & x, T & y, BinaryPredicate p)
    {
        if (p(x,y) == false) // overloaded operator()
        {
            return false;
        }
        std::swap(x,y);
        return true;
    }

    template<typename ConvToNum> int signo(const ConvToNum c)
    {
        if (c > 0)
            return 1;

        if (c < 0)
            return -1;

        return 0;
    }
}

#endif // ALGORITHM_H_INCLUDED
