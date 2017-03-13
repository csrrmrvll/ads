#ifndef ADS_HEAP_H
#define ADS_HEAP_H

#include "sorted_sequence.h"

namespace ads
{
    template<typename T,typename Compare = std::less<T>>
    class heap;

    template<typename T>
    using min_heap = heap<T>;

    template<typename T>
    using max_heap = heap<T,std::greater<T>>;

    template<typename T,typename Compare>
    class heap
    :   private sorted_sequence<T,Compare>
    {
        using cont = sorted_sequence<T,Compare>;
        constexpr cont & cnt()
        {
            return *this;
        }

        constexpr const cont & cnt() const
        {
            return *this;
        }

    public:
        // Member types
        using container_type = typename cont::container_type;
        using value_compare = Compare;
        using typename cont::value_type;
        using typename cont::size_type;
        using typename cont::iterator;
        using typename cont::const_iterator;
        using typename cont::reference;
        using typename cont::const_reference;
        // Member functions
        // Constructor
        explicit heap(const Compare & cmp = Compare())
        :   cont(cmp)
        {
        }

        template<typename Container>
        explicit heap(const Compare & cmp, Container && c)
        :   cont(cmp,std::move(c))
        {
        }

        heap(std::initializer_list<value_type> il)
        :   cont{std::move(il)}
        {
        }

        heap(std::initializer_list<value_type> il, const Compare & cmp)
        :   cont(std::move(il),cmp)
        {
        }

        heap(std::initializer_list<value_type> il, Compare && cmp)
        :   cont(std::move(il),std::move(cmp))
        {
        }

        template<typename Iterator>
        heap(range<Iterator> && r, const Compare & cmp)
        :   cont(cmp)
        {
        }

        template<typename Iterator>
        heap(range<Iterator> && r, Compare && cmp = Compare())
        :   cont(r,std::move(cmp))
        {
        }
        // Destructor
        ~heap() = default;
        // Copy constructor
        heap(const heap &) = default;
        // Move constructor
        heap(heap &&) = default;
        // Copy-assignment operator
        heap & operator=(const heap &) = default;
        // Move-assignment operator
        heap & operator=(heap &&) = default;
        // Assignment from initializer list operator
        heap & operator=(std::initializer_list<value_type> il)
        {
            heap other{il};
            this->swap(other);
            return *this;
        }
        // Access
        reference top()
        {
            return this->front();
        }

        const_reference top() const
        {
            return this->front();
        }

        using cont::begin;
        using cont::cbegin;
        using cont::rbegin;
        using cont::crbegin;
        using cont::end;
        using cont::cend;
        using cont::rend;
        using cont::crend;
        // Capacity
        using cont::empty;
        using cont::size;
        // Modifiers
        using cont::push;
        using cont::emplace;
        using cont::erase;
        using cont::pop;
        using cont::swap;

        template<typename U,typename Comp>
        friend bool operator==(const heap<U,Comp> & lhs,
                               const heap<U,Comp> & rhs);
        template<typename U,typename Comp>
        friend bool operator!=(const heap<U,Comp> & lhs,
                               const heap<U,Comp> & rhs);
        template<typename U,typename Comp>
        friend bool operator<(const heap<U,Comp> & lhs,
                              const heap<U,Comp> & rhs);
        template<typename U,typename Comp>
        friend bool operator<=(const heap<U,Comp> & lhs,
                               const heap<U,Comp> & rhs);
        template<typename U,typename Comp>
        friend bool operator>(const heap<U,Comp> & lhs,
                              const heap<U,Comp> & rhs);
        template<typename U,typename Comp>
        friend bool operator>=(const heap<U,Comp> & lhs,
                               const heap<U,Comp> & rhs);
    };

    template<typename T,typename Compare>
    bool operator==(const heap<T,Compare> & lhs, const heap<T,Compare> & rhs)
    {
        return lhs.cnt() == rhs.cnt();
    }

    template<typename T,typename Compare>
    bool operator!=(const heap<T,Compare> & lhs, const heap<T,Compare> & rhs)
    {
        return !(lhs == rhs);
    }

    template<typename T,typename Compare>
    bool operator<(const heap<T,Compare> & lhs, const heap<T,Compare> & rhs)
    {
        return lhs.cnt() < rhs.cnt();
    }

    template<typename T,typename Compare>
    bool operator<=(const heap<T,Compare> & lhs, const heap<T,Compare> & rhs)
    {
        return lhs < rhs || lhs == rhs;
    }

    template<typename T,typename Compare>
    bool operator>(const heap<T,Compare> & lhs, const heap<T,Compare> & rhs)
    {
        return !(lhs <= rhs);
    }

    template<typename T,typename Compare>
    bool operator>=(const heap<T,Compare> & lhs, const heap<T,Compare> & rhs)
    {
        return !(lhs < rhs);
    }

    template<typename T,typename Compare>
    void swap(heap<T,Compare> & lhs, heap<T,Compare> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_HEAP_H
