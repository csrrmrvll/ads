#ifndef ADS_ALGORITHM_H
#define ADS_ALGORITHM_H

#ifdef _MSC_VER
#define NOMINMAX
#endif

#include <algorithm>
#include <iterator>
#include "range.h"

namespace ads
{
    template<typename Container>
    bool is_end(const Container & c, typename Container::const_iterator it)
    {
        return end(c) == it;
    }

    template<typename Container>
    bool not_end(const Container & c, typename Container::const_iterator it)
    {
        return !is_end(c,it);
    }

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

    template<typename Container,typename OutputIterator>
    OutputIterator copy(const Container & c, OutputIterator oit)
    {
        return std::copy(begin(c),end(c),oit);
    }

    template<typename Container,typename OutputIterator,typename UnaryPredicate>
    OutputIterator copy_if(const Container & c, OutputIterator oit, UnaryPredicate p)
    {
        return std::copy_if(begin(c),end(c),oit,p);
    }

    template<typename Container>
    typename std::iterator_traits<typename Container::const_iterator>::difference_type
    count(const Container & c, const typename Container::value_type & v)
    {
        return std::count(begin(c),end(c),v);
    }

    template<typename Container,typename UnaryPredicate>
    typename std::iterator_traits<typename Container::const_iterator>::difference_type
    count_if(const Container & c, UnaryPredicate p)
    {
        return std::count_if(begin(c),end(c),p);
    }

    template<typename Container>
    range<typename Container::iterator>
    equal_range(const Container & c, const typename Container::value_type & v)
    {
        return std::equal_range(begin(c),end(c),v);
    }

    template<typename Container,typename UnaryPredicate>
    range<typename Container::const_iterator>
    equal_range(const Container & c, const typename Container::value_type & v, UnaryPredicate p)
    {
        return make_range(std::equal_range(begin(c),end(c),v,p));
    }

    template<typename Container>
    struct find_result
    {
        using const_iterator = typename Container::const_iterator;

        const_iterator pos;
        bool found;
    };

    template<typename Container>
    find_result<Container> make_find_result(const Container & c, typename Container::const_iterator it)
    {
        return find_result<Container>{it,not_end(c,it)};
    }

    template<typename Container>
    find_result<Container> find(const Container & c, const typename Container::value_type & v)
    {
        auto it = std::find(begin(c),end(c),v);
        return make_find_result(c,it);
    }

    template<typename Container,typename UnaryPredicate>
    find_result<Container> find_if(const Container & c, UnaryPredicate p)
    {
        auto it = std::find_if(begin(c),end(c),p);
        return make_find_result(c,it);
    }

    template<typename Container,typename UnaryPredicate>
    find_result<Container> find_if_not(const Container & c, UnaryPredicate p)
    {
        auto it = std::find_if_not(begin(c),end(c),p);
        return make_find_result(c,it);
    }

    template<typename Container, typename T>
    void iota(Container & c, T value)
    {
        return std::iota(begin(c),end(c),value);
    }

    template<typename Container>
    bool is_heap(const Container & c)
    {
        return std::is_heap(begin(c),end(c));
    }

    template<typename Container,typename Compare>
    bool is_heap(const Container & c, Compare comp)
    {
        return std::is_heap(begin(c),end(c),comp);
    }

    template<typename Container>
    range<typename Container::iterator>
    lower_bound(const Container & c, const typename Container::value_type & v)
    {
        return std::lower_bound(begin(c),end(c),v);
    }

    template<typename Container>
    void make_heap(Container & c)
    {
        return std::make_heap(begin(c),end(c));
    }

    template<typename Container,typename Compare>
    void make_heap(Container & c, Compare comp)
    {
        return std::make_heap(begin(c),end(c),comp);
    }

    template<typename Container>
    void pop_heap(Container & c)
    {
        return std::pop_heap(begin(c),end(c));
    }

    template<typename Container,typename Compare>
    void pop_heap(Container & c, Compare comp)
    {
        return std::pop_heap(begin(c),end(c),comp);
    }

    template<typename Container>
    void push_heap(Container & c)
    {
        return std::push_heap(begin(c),end(c));
    }

    template<typename Container,typename Compare>
    void push_heap(Container & c, Compare comp)
    {
        return std::push_heap(begin(c),end(c),comp);
    }

    template<typename Container,typename UnaryPredicate>
    range<typename Container::iterator>
    upper_bound(const Container & c, const typename Container::value_type & v, UnaryPredicate p)
    {
        return std::upper_bound(begin(c),end(c),v,p);
    }

    template<typename T>
    bool swap_if(T & x, T & y, bool b)
    {
        if (b)
        {
            std::swap(x,y);
        }
        return b;
    }

    template<typename T,typename BinaryPredicate>
    bool swap_if(T & x, T & y, BinaryPredicate p)
    {
        bool result = p(x,y);
        if (p(x,y))
        {
            std::swap(x,y);
        }
        return result;
    }
}

#endif // ADS_ALGORITHM_H
