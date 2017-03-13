#ifndef ADS_SEQUENCE_H
#define ADS_SEQUENCE_H

#include <vector>
#include "range.h"

namespace ads
{
    template<typename T,typename Container = std::vector<T>>
    class sequence;

    template<typename T,typename Container>
    class sequence
    :   private Container
    {
    protected:
        using cont = Container;

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
        using container_type = cont;
        using typename cont::value_type;
        using typename cont::size_type;
        using typename cont::difference_type;
        using typename cont::reference;
        using typename cont::const_reference;
        using typename cont::pointer;
        using typename cont::const_pointer;
        using typename cont::iterator;
        using typename cont::const_iterator;
        using typename cont::reverse_iterator;
        using typename cont::const_reverse_iterator;
        // Member functions
        // Constructor (compiler generated)
        // Destructor (compiler generated)
        // operator= (compiler generated)
        using cont::assign;

        template<typename Iterator>
        void assign(range<Iterator> && r)
        {
            cont::assign(std::begin(r),std::end(r));
        }
        // Access
        using cont::at;
        using cont::operator[];
        using cont::front;
        using cont::back;
        using cont::data;
        // Iterators
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
        using cont::max_size;
        using cont::reserve;
        using cont::capacity;
        using cont::shrink_to_fit;
        // Modifiers
        using cont::clear;
        using cont::insert;

        template<typename Iterator>
        iterator insert(const_iterator pos, range<Iterator> && r)
        {
            return cont::insert(pos,std::begin(r),std::end(r));
        }

        using cont::emplace;
        using cont::erase;

        iterator erase(range<iterator> && r)
        {
            return cont::erase(std::begin(r),std::end(r));
        }

        using cont::push_back;
        using cont::emplace_back;
        using cont::pop_back;
        using cont::resize;
        using cont::swap;

        template<typename U,typename Cont>
        friend bool operator==(const sequence<U,Cont> & lhs,
                                const sequence<U,Cont> & rhs);
        template<typename U,typename Cont>
        friend bool operator!=(const sequence<U,Cont> & lhs,
                                const sequence<U,Cont> & rhs);
        template<typename U,typename Cont>
        friend bool operator<(const sequence<U,Cont> & lhs,
                                const sequence<U,Cont> & rhs);
        template<typename U,typename Cont>
        friend bool operator<=(const sequence<U,Cont> & lhs,
                                const sequence<U,Cont> & rhs);
        template<typename U,typename Cont>
        friend bool operator>(const sequence<U,Cont> & lhs,
                                const sequence<U,Cont> & rhs);
        template<typename U,typename Cont>
        friend bool operator>=(const sequence<U,Cont> & lhs,
                                const sequence<U,Cont> & rhs);
    };

    template<typename T,typename Container>
    bool operator==(const sequence<T,Container> & lhs,
                    const sequence<T,Container> & rhs)
    {
        return lhs.cnt() == rhs.cnt();
    }

    template<typename T,typename Container>
    bool operator!=(const sequence<T,Container> & lhs,
                    const sequence<T,Container> & rhs)
    {
        return !(lhs == rhs);
    }

    template<typename T,typename Container>
    bool operator<(const sequence<T,Container> & lhs,
                    const sequence<T,Container> & rhs)
    {
        return lhs.cnt() < rhs.cnt();
    }

    template<typename T,typename Container>
    bool operator<=(const sequence<T,Container> & lhs,
                    const sequence<T,Container> & rhs)
    {
        return lhs < rhs || lhs == rhs;
    }

    template<typename T,typename Container>
    bool operator>(const sequence<T,Container> & lhs,
                    const sequence<T,Container> & rhs)
    {
        return !(lhs <= rhs);
    }

    template<typename T,typename Container>
    bool operator>=(const sequence<T,Container> & lhs,
                    const sequence<T,Container> & rhs)
    {
        return !(lhs < rhs);
    }

    template<typename T,typename Container>
    void swap(sequence<T,Container> & lhs, sequence<T,Container> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_SEQUENCE_H
