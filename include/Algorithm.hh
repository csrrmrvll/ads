#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>

#ifdef _MSC_VER
#define NOMINMAX
#endif

namespace csr
{
    template<class Container,typename Functor> inline
    Functor for_all(Container& c,Functor& f)
    { return std::for_each(c.begin(),c.end(),f); }

    //	Predicados y funciones para algoritmos.
    template<class In,class T>
    inline std::pair<In,bool> find_pos(In first,In last,T val)
    {
        In pos = std::find(first,last,val);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    template<class In,class Pred>
    inline std::pair<In,bool> find_pos_if(In first,In last,Pred p)
    {
        In pos = std::find_if(first,last,p);
        bool found = (pos != last);
        return std::make_pair(pos,found);
    }

    // Esta sobrecarga es para usarse con std::map<Key,T>.
    template<typename Container>
    inline std::pair<typename Container::const_iterator,bool>
    find_pos(const Container& cont,const typename Container::value_type& val)
    {
        return find_pos(cont.begin(),cont.end(),val);
    }

    template<typename Container,typename Predicate>
    inline std::pair<typename Container::const_iterator,bool>
    find_pos_if(const Container& cont,Predicate pred)
    {
        return find_pos_if(cont.begin(),cont.end(),pred);
    }

    template<class T> inline bool swap_if(T *x,T *y,bool b)
    {
        if (b == false)
            return false;

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
