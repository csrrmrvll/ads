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
        using value_type = typename cont::value_type;
        using size_type = typename cont::size_type;
        using difference_type = typename cont::difference_type;
        using reference = typename cont::reference;
        using const_reference = typename cont::const_reference;
        using pointer = typename cont::pointer;
        using const_pointer = typename cont::const_pointer;
        using iterator = typename cont::iterator;
        using const_iterator = typename cont::const_iterator;
        using reverse_iterator = typename cont::reverse_iterator;
        using const_reverse_iterator = typename cont::const_reverse_iterator;
        // Member functions
        // Constructor
        sequence() = default;
        explicit sequence(size_type count, const T & value = T())
        :   cont(count,value)
        {
        }

        template<typename Iterator>
        sequence(range<Iterator> && r)
        :   cont(std::begin(r),std::end(r))
        {
        }

        sequence(std::initializer_list<value_type> il)
        :   cont{std::move(il)}
        {
        }
        // Destructor
        ~sequence() = default;
        // Copy constructor
        sequence(const sequence & other) = default;
        // Move constructor
        sequence(sequence && other) = default;
        // Copy-assignment operator
        sequence & operator=(const sequence & other) = default;
        // Move-assignment operator
        sequence & operator=(sequence && other) = default;
        // Assignment from initializer list operator
        sequence & operator=(std::initializer_list<value_type> il)
        {
            sequence other(il);
            this->swap(other);
            return *this;
        }
        // Assign
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
        return Container::operator=(lhs,rhs);
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
        return Container::operator<(lhs,rhs);
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
