#ifndef ADS_HEAP_H
#define ADS_HEAP_H

#include "sorted_sequence.h"

namespace ads
{
    template
    <
        typename T,
        typename Compare = std::less<T>,
        typename Container = sorted_sequence<T,Compare>
    >
    class heap;

    template<typename T>
    using min_heap = heap<T>;

    template<typename T>
    using max_heap = heap<T,std::greater<T>>;

    template<typename T,typename Compare,typename Container>
    class heap
    :   private Container
    {
    public:
        // Member types
        using cont = Container;
        using container_type = cont;
        using value_compare = Compare;
        using typename cont::value_type;
        using typename cont::size_type;
        using typename cont::iterator;
        using typename cont::const_iterator;
        using typename cont::reference;
        using typename cont::const_reference;
        // Member functions
        // Constructor (compiler generated)
        heap(const Compare & cmp)
        :   cont(cmp)
        {
        }
        // Destructor (compiler generated)
        // Copy constructor (compiler generated)
        // operator= (compiler generated)
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
    };

    template<typename Container,typename Compare>
    void swap(heap<Container,Compare> & lhs, heap<Container,Compare> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_HEAP_H
