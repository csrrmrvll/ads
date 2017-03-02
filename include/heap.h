#ifndef ADS_HEAP_H
#define ADS_HEAP_H

#include <utility>
#include <vector>
#include "algorithm.h"
#include "range.h"

namespace ads
{
    template<typename T,typename Compare = std::less<T>,typename Container = std::vector<T>>
    class heap;

    template<typename T>
    using max_heap = heap<T>;

    template<typename T>
    using min_heap = heap<T,std::greater<T>>;

    template<typename T,typename Compare,typename Container>
    class heap
    :   private Container
    {
        using base = Container;
        using base::erase;
    public:
        using container_type = base;
        using typename base::iterator;
        using typename base::const_iterator;
        using typename base::reference;
        using typename base::const_reference;
        using typename base::size_type;
        using typename base::value_type;
        using base::begin;
        using base::end;
        using base::empty;
        using base::size;

        heap() = default;

        explicit heap(const Compare & comp)
        :   base(),
            comp_(comp)
        {
        }

        explicit heap(Compare && comp)
        :   base(),
            comp_(comp)
        {
        }

        explicit heap(const Container & cont)
        :   base(std::move(cont)),
            comp_()
        {
            this->make_heap();
        }

        explicit heap(Container && cont)
        :   base(std::move(cont)),
            comp_()
        {
            this->make_heap();
        }

        heap(const Container & cont, const Compare & comp)
        :   base(cont),
            comp_(comp)
        {
            this->make_heap();
        }

        heap(const Container & cont, Compare && comp)
        :   base(cont),
            comp_(std::move(comp))
        {
            this->make_heap();
        }

        heap(Container && cont, const Compare & comp)
        :   base(std::move(cont)),
            comp_(comp)
        {
            this->make_heap();
        }

        heap(Container && cont, Compare && comp)
        :   base(std::move(cont)),
            comp_(std::move(comp))
        {
            this->make_heap();
        }

        heap(std::initializer_list<value_type> il)
        :   base(il),
            comp_()
        {
            this->make_heap();
        }

        heap(const heap & other) = default;
        heap(heap && other) = default;

        heap & operator=(const heap & other) = default;
        heap & operator=(heap && other) = default;
        heap & operator=(std::initializer_list<value_type> il)
        {
            heap other(il);
            this->swap(other);
            this->make_heap();
            return *this;
        }

        ~heap() = default;

        reference top() { return this->front(); }
        const_reference top() const { return this->front(); }

        void push(const value_type & v)
        {
            this->push_back(v);
            this->push_heap();
        }

        void push(value_type && v)
        {
            this->push_back(std::move(v));
            this->push_heap();
        }

        template<typename... Args>
        reference emplace(Args && ...args)
        {
            auto v = this->emplace_back(std::forward<Args>(args)...);
            this->push_heap();
            return v;
        }

        iterator erase(const value_type & v)
        {
            auto r = equal_range(*this,v,this->comp_);
            return this->erase(r.begin(),r.end());
        }

        value_type pop()
        {
            auto v = this->top();
            pop_heap(*this,this->comp_);
            this->pop_back();
            return v;
        }

        void swap(heap & other)
        {
            base::swap(other);
            std::swap(this->comp_,other.comp_);
        }

    private:
        void make_heap()
        {
            ads::make_heap(*this,this->comp_);
        }

        void push_heap()
        {
            ads::push_heap(*this,this->comp_);
        }

        Compare comp_;
    };

    template<typename Container,typename Compare>
    void swap(heap<Container,Compare> & lhs, heap<Container,Compare> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_HEAP_H
