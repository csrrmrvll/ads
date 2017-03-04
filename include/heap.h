#ifndef ADS_HEAP_H
#define ADS_HEAP_H

#include <utility>
#include <vector>
#include "algorithm.h"
#include "range.h"

namespace ads
{
    template<
        typename T,
        typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type>>
    class heap;

    template<typename T>
    using max_heap = heap<T>;

    template<typename T>
    using min_heap = heap<T,std::greater<T>>;

    template<typename T,typename Container,typename Compare>
    class heap
    :   private Container
    {
        void sort()
        {
            make_heap(*this,this->comp_);
        }

        void sort_after_push()
        {
            push_heap(*this,this->comp_);
        }

        void insert_and_sort(auto first, auto last)
        {
            base::insert(base::end(),first,last);
            this->sort();
        }

    public:
        // Member types
        using base = Container;
        using container_type = base;
        using value_compare = Compare;
        using typename base::value_type;
        using typename base::size_type;
        using typename base::iterator;
        using typename base::const_iterator;
        using typename base::reference;
        using typename base::const_reference;
        // Member functions
        // Constructor
        explicit heap(const Compare & comp = Compare(), Container && cont = Container())
        :   base(std::move(cont)),
            comp_(comp)
        {
            this->sort();
        }

        heap(const Compare & comp, const Container & cont)
        :   base(cont),
            comp_(comp)
        {
            this->sort();
        }

        heap(std::initializer_list<value_type> il)
        :   base(std::move(il)),
            comp_()
        {
            this->sort();
        }

        heap(std::initializer_list<value_type> il, const Compare & comp)
        :   base(std::move(il)),
            comp_(comp)
        {
            this->sort();
        }

        heap(std::initializer_list<value_type> il, Compare && comp)
        :   base(il),
            comp_(std::move(comp))
        {
            this->sort();
        }

        template<typename Iterator>
        heap(Iterator first, Iterator last, const Compare & comp, const Container & cont)
        :   base(cont),
            comp_(comp)
        {
            this->insert_and_sort(first,last);
        }

        template<typename Iterator>
        heap(Iterator first, Iterator last, const Compare & comp = Compare(), Container && cont = Container())
        :   base(std::move(cont)),
            comp_(std::move(comp))
        {
            this->insert_and_sort(first,last);
        }
        // Copy constructor
        heap(const heap & other) = default;
        // Move constructor
        heap(heap && other) = default;
        // Copy-assignment operator
        heap & operator=(const heap & other) = default;
        // Move-assignment operator
        heap & operator=(heap && other) = default;
        // Assignment from initializer list operator
        heap & operator=(std::initializer_list<value_type> il)
        {
            heap other(il);
            this->swap(other);
            return *this;
        }
        // Destructor
        ~heap() = default;
        // Access
        reference top() { return this->front(); }

        const_reference top() const { return this->front(); }

        using base::begin;
        using base::end;
        using base::cbegin;
        using base::cend;
        // Capacity
        using base::empty;
        using base::size;
        // Modifiers
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

        template<typename... Args>
        void emplace(Args && ...args)
        {
            auto v = this->emplace_back(std::forward<Args>(args)...);
            this->sort_after_push();
            return v;
        }

        iterator erase(const value_type & v)
        {
            auto r = equal_range(*this,v,this->comp_);
            return base::erase(std::begin(r),std::end(r));
        }

        value_type pop()
        {
            auto v = this->top();
            pop_heap(*this,this->comp_);
            base::pop_back();
            return v;
        }

        void swap(heap & other)
        {
            base::swap(other);
            std::swap(this->comp_,other.comp_);
        }

    private:
        Compare comp_;
    };

    template<typename Container,typename Compare>
    void swap(heap<Container,Compare> & lhs, heap<Container,Compare> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_HEAP_H
