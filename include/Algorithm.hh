#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include <algorithm>

#ifdef _MSC_VER
#define NOMINMAX
#endif

namespace csr
{
    template<typename Container,typename Functor> inline
    Functor forEach(Container & c, Functor & f)
    { return std::for_each(c.begin(),c.end(),f); }

    template<typename Container>
    std::pair<typename Container::const_iterator,bool> find(const Container & c, const typename Container::value_type & v)
    {
        auto    last = end(c),
                pos = std::find(begin(c),last,v);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<typename Container,typename Predicate>
    std::pair<typename Container::const_iterator,bool> find_if(const Container & c, Predicate p)
    {
        auto    last = end(c),
                pos = std::find_if(begin(c),last,p);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<class T> inline bool swap_if(T *x,T *y,bool b)
    {
        if (b == false)
        {
            return false;
        }
        swap(*x,*y);
        return true;
    }

    template<class T,class Pred> inline bool swap_if(T *x,T *y,Pred p)
    {
        p(*y); // needs an explicit constructor in order to work properly.
        if (p(x) == false) // overloaded operator()
            return false;

        swap(*x,*y);
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
