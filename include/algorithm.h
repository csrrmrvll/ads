#ifndef ADS_ALGORITHM_H
#define ADS_ALGORITHM_H

#include <algorithm>
#include <iterator>

#ifdef _MSC_VER
#define NOMINMAX
#endif

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
    countIf(const Container & c, UnaryPredicate p)
    {
        return std::count_if(begin(c),end(c),p);
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

    template<typename T>
    bool swapIf(T & x, T & y, bool b)
    {
        if (b)
        {
            std::swap(x,y);
        }
        return b;
    }

    template<typename T,typename BinaryPredicate>
    bool swapIf(T & x, T & y, BinaryPredicate p)
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
