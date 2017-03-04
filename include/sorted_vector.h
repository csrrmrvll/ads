#ifndef ADS_SORTED_VECTOR_H
#define ADS_SORTED_VECTOR_H

#include <utility>
#include <vector>
#include "algorithm.h"
#include "range.h"

namespace ads
{
    template
    <
        typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<T>
    >
    class sorted_vector;

    template<typename T>
    using increase_sequence = sorted_vector<T>;

    template<typename T>
    using decrease_sequence = sorted_vector<T,std::vector<T>,std::greater<T>>;

    template<typename T,typename Container,typename Compare>
    class sorted_vector
    :   private Container,
        private Compare
    {
        void sort()
        {
            cont & cnt = *this;
            comp & cmp = *this;
            make_heap(cnt,cmp);
        }

        void sort_after_push()
        {
            cont & cnt = *this;
            comp & cmp = *this;
            push_heap(cnt,cmp);
        }

        using cont = Container;
        using comp = Compare;

    public:
        // Member types
        using container_type = cont;
        using value_compare = comp;
        using typename cont::value_type;
        using typename cont::size_type;
        using typename cont::iterator;
        using typename cont::const_iterator;
        using typename cont::reference;
        using typename cont::const_reference;
        // Member functions
        // Constructor
        explicit sorted_vector(const Compare & cmp = Compare(), Container && c = Container())
        :   cont(std::move(c)),
            comp(cmp)
        {
            this->sort();
        }

        sorted_vector(const Compare & cmp, const Container & c)
        :   cont(c),
            comp(cmp)
        {
            this->sort();
        }

        sorted_vector(std::initializer_list<value_type> il)
        :   cont(std::move(il)),
            comp()
        {
            this->sort();
        }

        sorted_vector(std::initializer_list<value_type> il, const Compare & cmp)
        :   cont(std::move(il)),
            comp(cmp)
        {
            this->sort();
        }

        sorted_vector(std::initializer_list<value_type> il, Compare && cmp)
        :   cont(il),
            comp(std::move(cmp))
        {
            this->sort();
        }

        template<typename Iterator>
        sorted_vector(Iterator first, Iterator last, const Compare & cmp, const Container & cnt)
        :   cont(cnt),
            comp(cmp)
        {
            this->insert(first,last);
        }

        template<typename Iterator>
        sorted_vector(Iterator first, Iterator last, const Compare & cmp = Compare(), Container && cnt = Container())
        :   cont(std::move(cnt)),
            comp(std::move(cmp))
        {
            this->insert(first,last);
        }
        // Copy constructor
        sorted_vector(const sorted_vector & other) = default;
        // Move constructor
        sorted_vector(sorted_vector && other) = default;
        // Copy-assignment operator
        sorted_vector & operator=(const sorted_vector & other) = default;
        // Move-assignment operator
        sorted_vector & operator=(sorted_vector && other) = default;
        // Assignment from initializer list operator
        sorted_vector & operator=(std::initializer_list<value_type> il)
        {
            sorted_vector other(il);
            this->swap(other);
            return *this;
        }
        // Destructor
        ~sorted_vector() = default;
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
            this->sort_after_push();
        }

        void push(value_type && v)
        {
            this->push_back(std::move(v));
            this->sort_after_push();
        }

        void push(auto first, auto last)
        {
            for (auto v : make_range(first, last))
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
            auto r = equal_range(*this,v,this->comp);
            return cont::erase(std::begin(r),std::end(r));
        }

        value_type pop()
        {
            auto v = this->top();
            pop_heap(*this,this->comp);
            cont::pop_back();
            return v;
        }

        using cont::resize;

        void swap(sorted_vector & other)
        {
            cont::swap(other);
            const comp  & mecomp = *this,
                        & ocomp = other;
            std::swap(mecomp,ocomp);
        }
    };

    template<typename Container,typename Compare>
    void swap(sorted_vector<Container,Compare> & lhs, sorted_vector<Container,Compare> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_SORTED_VECTOR_H
