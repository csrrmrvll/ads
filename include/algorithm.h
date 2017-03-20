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
    template<typename Range>
    bool is_end(const Range & r, typename Range::const_iterator it)
    {
        return end(r) == it;
    }

    template<typename Range>
    bool not_end(const Range & r, typename Range::const_iterator it)
    {
        return !is_end(r,it);
    }

    template<typename Range,typename UnaryPredicate>
    bool allOf(const Range & r, UnaryPredicate p)
    {
        return std::all_of(begin(r),end(r),p);
    }

    template<typename Range,typename UnaryPredicate>
    bool anyOf(const Range & r, UnaryPredicate p)
    {
        return std::any_of(begin(r),end(r),p);
    }

    template<typename Range,typename UnaryPredicate>
    bool noneOf(const Range & r, UnaryPredicate p )
    {
        return std::none_of(begin(r),end(r),p);
    }

    template<typename Range,typename UnaryFunction> inline
    UnaryFunction forEach(const Range & r, UnaryFunction f)
    {
        return std::for_each(begin(r),end(r),f);
    }

    template<typename Range,typename OutputIterator>
    OutputIterator copy(const Range & r, OutputIterator oit)
    {
        return std::copy(begin(r),end(r),oit);
    }

    template<typename Range,typename OutputIterator,typename UnaryPredicate>
    OutputIterator copy_if(const Range & r, OutputIterator oit, UnaryPredicate p)
    {
        return std::copy_if(begin(r),end(r),oit,p);
    }

    template<typename Range>
    typename std::iterator_traits<typename Range::iterator>::difference_type
    count(const Range & r, const typename Range::value_type & v)
    {
        return std::count(begin(r),end(r),v);
    }

    template<typename Range,typename UnaryPredicate>
    typename std::iterator_traits<typename Range::iterator>::difference_type
    count_if(const Range & r, UnaryPredicate p)
    {
        return std::count_if(begin(r),end(r),p);
    }

    template<typename Range>
    range<typename Range::iterator>
    equal_range(const Range & r, const typename Range::value_type & v)
    {
        return std::equal_range(begin(r),end(r),v);
    }

    template<typename Range,typename UnaryPredicate>
    range<typename Range::iterator>
    equal_range(const Range & r, const typename Range::value_type & v, UnaryPredicate p)
    {
        return make_range(std::equal_range(begin(r),end(r),v,p));
    }

    template<typename Range>
    struct find_result
    {
        using const_iterator = typename Range::const_iterator;

        const_iterator pos;
        bool found;
    };

    template<typename Range>
    find_result<Range> make_find_result(const Range & r, typename Range::const_iterator it)
    {
        return find_result<Range>{it,not_end(r,it)};
    }

    template<typename Range>
    find_result<Range> find(const Range & r, const typename Range::value_type & v)
    {
        auto it = std::find(begin(r),end(r),v);
        return make_find_result(r,it);
    }

    template<typename Range,typename UnaryPredicate>
    find_result<Range> find_if(const Range & r, UnaryPredicate p)
    {
        auto it = std::find_if(begin(r),end(r),p);
        return make_find_result(r,it);
    }

    template<typename Range,typename UnaryPredicate>
    find_result<Range> find_if_not(const Range & r, UnaryPredicate p)
    {
        auto it = std::find_if_not(begin(r),end(r),p);
        return make_find_result(r,it);
    }

    template<typename Range, typename T>
    void iota(Range & r, T value)
    {
        return std::iota(begin(r),end(r),value);
    }

    template<typename Range>
    bool is_heap(const Range & r)
    {
        return std::is_heap(begin(r),end(r));
    }

    template<typename Range,typename Compare>
    bool is_heap(const Range & r, Compare comp)
    {
        return std::is_heap(begin(r),end(r),comp);
    }

    template<typename Range>
    range<typename Range::iterator>
    lower_bound(const Range & r, const typename Range::value_type & v)
    {
        return std::lower_bound(begin(r),end(r),v);
    }

    template<typename Range>
    void make_heap(Range & r)
    {
        return std::make_heap(begin(r),end(r));
    }

    template<typename Range,typename Compare>
    void make_heap(Range & r, Compare comp)
    {
        return std::make_heap(begin(r),end(r),comp);
    }

    template<typename Range>
    void pop_heap(Range & r)
    {
        return std::pop_heap(begin(r),end(r));
    }

    template<typename Range,typename Compare>
    void pop_heap(Range & r, Compare comp)
    {
        return std::pop_heap(begin(r),end(r),comp);
    }

    template<typename Range>
    void push_heap(Range & r)
    {
        return std::push_heap(begin(r),end(r));
    }

    template<typename Range,typename Compare>
    void push_heap(Range & r, Compare comp)
    {
        return std::push_heap(begin(r),end(r),comp);
    }

    template<typename Range,typename UnaryPredicate>
    range<typename Range::iterator>
    upper_bound(const Range & r, const typename Range::value_type & v, UnaryPredicate p)
    {
        return std::upper_bound(begin(r),end(r),v,p);
    }

    template<typename Iterator>
    void sort(range<Iterator> && r)
    {
        std::sort(begin(r),end(r));
    }

    template<typename Iterator,typename Compare>
    void sort(range<Iterator> && r, Compare comp)
    {
        std::sort(begin(r),end(r),comp);
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
