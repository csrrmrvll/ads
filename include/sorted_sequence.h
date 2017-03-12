#ifndef ADS_SORTED_SEQUENCE_H
#define ADS_SORTED_SEQUENCE_H

#include "algorithm.h"
#include "sequence.h"

namespace ads
{
    template
    <
        typename T,
        typename Compare = std::less<T>,
        typename Container = sequence<T>
    >
    class sorted_sequence;

    template<typename T>
    using increase_sequence = sorted_sequence<T>;

    template<typename T>
    using decrease_sequence = sorted_sequence<T,std::greater<T>>;

    template<typename T,typename Compare,typename Container>
    class sorted_sequence
    :   private Container,
        private Compare
    {
        using cont = Container;
        using comp = Compare;

        constexpr cont & cnt()
        {
            return *this;
        }

        constexpr const cont & cnt() const
        {
            return *this;
        }

        constexpr comp & cmp()
        {
            return *this;
        }

        constexpr const comp & cmp() const
        {
            return *this;
        }

        void sort()
        {
            make_heap(cnt(),cmp());
        }

    public:
        // Member types
        using container_type = cont;
        using value_compare = comp;
        using typename cont::value_type;
        using typename cont::size_type;
        using typename cont::iterator;
        using typename cont::const_iterator;
        using typename cont::reverse_iterator;
        using typename cont::const_reverse_iterator;
        using typename cont::reference;
        using typename cont::const_reference;
        // Member functions
        // Constructor
        explicit sorted_sequence(const Compare & cmp = Compare(), Container && c = Container())
        :   cont(std::move(c)),
            comp(cmp)
        {
            this->sort();
        }

        sorted_sequence(const Compare & cmp, const Container & c)
        :   cont(c),
            comp(cmp)
        {
            this->sort();
        }

        sorted_sequence(std::initializer_list<value_type> il)
        :   cont{std::move(il)},
            comp()
        {
            this->sort();
        }

        sorted_sequence(std::initializer_list<value_type> il, const Compare & cmp)
        :   cont{std::move(il)},
            comp(cmp)
        {
            this->sort();
        }

        sorted_sequence(std::initializer_list<value_type> il, Compare && cmp)
        :   cont{std::move(il)},
            comp(std::move(cmp))
        {
            this->sort();
        }

        template<typename Iterator>
        sorted_sequence(range<Iterator> && r, const Compare & cmp, const Container & cnt)
        :   cont(cnt),
            comp(cmp)
        {
            this->push(r);
        }

        template<typename Iterator>
        sorted_sequence(range<Iterator> && r, const Compare & cmp = Compare(), Container && cnt = Container())
        :   cont(std::move(cnt)),
            comp(std::move(cmp))
        {
            this->push(r);
        }
        // Copy constructor
        sorted_sequence(const sorted_sequence & other) = default;
        // Move constructor
        sorted_sequence(sorted_sequence && other) = default;
        // Copy-assignment operator
        sorted_sequence & operator=(const sorted_sequence & other) = default;
        // Move-assignment operator
        sorted_sequence & operator=(sorted_sequence && other) = default;
        // Assignment from initializer list operator
        sorted_sequence & operator=(std::initializer_list<value_type> il)
        {
            sorted_sequence other(il);
            this->swap(other);
            return *this;
        }
        // Destructor
        ~sorted_sequence() = default;
        // Access
        using cont::at;
        using cont::front;
        using cont::back;
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

        void push(const value_type & v)
        {
            this->push_back(v);
            push_heap(cnt(),cmp());
        }

        void push(value_type && v)
        {
            this->push_back(std::move(v));
            push_heap(cnt(),cmp());
        }

        template<typename Iterator>
        void push(range<Iterator> && r)
        {
            for (auto v : r)
            {
                this->push(v);
            }
        }

        template<typename... Args>
        void emplace(Args && ...args)
        {
            this->emplace(std::forward<Args>(args)...);
            this->sort();
        }

        iterator erase(const value_type & v)
        {
            auto r = equal_range(cnt(),v,comp());
            return cont::erase(std::begin(r),std::end(r));
        }

        value_type pop()
        {
            auto v = this->top();
            pop_heap(cnt(),cmp());
            cont::pop_back();
            return v;
        }

        void swap(sorted_sequence & other)
        {
            cont::swap(other);
            std::swap(cmp(),other.cmp());
        }

        template<typename Comp,typename Cont>
        friend bool operator==(const sorted_sequence<Comp,Cont> & lhs,
                                const sorted_sequence<Comp,Cont> & rhs);
        template<typename Comp,typename Cont>
        friend bool operator!=(const sorted_sequence<Comp,Cont> & lhs,
                                const sorted_sequence<Comp,Cont> & rhs);
        template<typename Comp,typename Cont>
        friend bool operator<(const sorted_sequence<Comp,Cont> & lhs,
                                const sorted_sequence<Comp,Cont> & rhs);
        template<typename Comp,typename Cont>
        friend bool operator<=(const sorted_sequence<Comp,Cont> & lhs,
                                const sorted_sequence<Comp,Cont> & rhs);
        template<typename Comp,typename Cont>
        friend bool operator>(const sorted_sequence<Comp,Cont> & lhs,
                                const sorted_sequence<Comp,Cont> & rhs);
        template<typename Comp,typename Cont>
        friend bool operator>=(const sorted_sequence<Comp,Cont> & lhs,
                                const sorted_sequence<Comp,Cont> & rhs);
    };

    template<typename Comp,typename Cont>
    bool operator==(const sorted_sequence<Comp,Cont> & lhs,
                            const sorted_sequence<Comp,Cont> & rhs)
    {
        return lhs.cnt() == rhs.cnt() && lhs.cmp() == rhs.cmp();
    }


    template<typename Comp,typename Cont>
    bool operator!=(const sorted_sequence<Comp,Cont> & lhs,
                            const sorted_sequence<Comp,Cont> & rhs)
    {
        return !(lhs == rhs);
    }

    template<typename Comp,typename Cont>
    bool operator<(const sorted_sequence<Comp,Cont> & lhs,
                            const sorted_sequence<Comp,Cont> & rhs)
    {
        return lhs.cnt() < rhs.cnt();
    }

    template<typename Comp,typename Cont>
    bool operator<=(const sorted_sequence<Comp,Cont> & lhs,
                            const sorted_sequence<Comp,Cont> & rhs)
    {
        return lhs < rhs || lhs == rhs;
    }

    template<typename Comp,typename Cont>
    bool operator>(const sorted_sequence<Comp,Cont> & lhs,
                            const sorted_sequence<Comp,Cont> & rhs)
    {
        return !(lhs <= rhs);
    }

    template<typename Comp,typename Cont>
    bool operator>=(const sorted_sequence<Comp,Cont> & lhs,
                            const sorted_sequence<Comp,Cont> & rhs)
    {
        return !(lhs < rhs);
    }

    template<typename Container,typename Compare>
    void swap(sorted_sequence<Container,Compare> & lhs, sorted_sequence<Container,Compare> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_SORTED_SEQUENCE_H
