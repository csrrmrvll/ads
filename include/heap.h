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


        heap()
        :   base{},
            comp_{}
        {
        }

        explicit heap(const Compare & comp)
        :   base{},
            comp_{comp}
        {
        }

    //    explicit heap(Compare && comp)
    //    :   base{},
    //        comp_{std::move(comp)}
    //    {
    //    }
    //
    //    explicit heap(const Container & cont, const Compare & comp)
    //    :   base{cont},
    //        comp_{comp}
    //    {
    //    }
    //
    //    explicit heap(const Container & cont, Compare && comp)
    //    :   base{cont},
    //        comp_{std::move(comp)}
    //    {
    //    }
    //
    //    explicit heap(Container && cont, const Compare & comp)
    //    :   base{std::move(cont)},
    //        comp_{comp}
    //    {
    //    }
    //
        explicit heap(Container && cont = Container(), Compare && comp = Compare())
        :   base{std::move(cont)},
            comp_{std::move(comp)}
        {
        }

    //    heap(range<iterator> r, Compare && comp = Compare())
    //    :   base{begin(r),end(r)},
    //        comp_{std::move(comp)}
    //    {
    //    }

        heap(const heap & other) = default;
        heap(heap && other) = default;
        heap & operator=(const heap & other) = default;
        heap & operator=(heap && other) = default;
        ~heap() = default;

        template<class Alloc>
        explicit heap(const Alloc & alloc)
        :   base(alloc),
            comp_{}
        {
        }

        template<class Alloc>
        explicit heap(const Alloc & alloc, const Compare & comp)
        :   base(alloc),
            comp_{comp}
        {
        }

        template<class Alloc>
        explicit heap(const Alloc & alloc, Compare && comp)
        :   base(alloc),
            comp_{std::move(comp)}
        {
        }

        template<class Alloc>
        heap(const Container & cont, const Alloc & alloc)
        :   base(cont, alloc),
            comp_{}
        {
        }

        template<class Alloc>
        heap(const Container & cont, const Alloc & alloc, const Compare & comp)
        :   base(cont, alloc),
            comp_{comp}
        {
        }

        template<class Alloc>
        heap(const Container && cont, const Alloc & alloc, Compare && comp)
        :   base(cont, alloc),
            comp_{std::move(comp)}
        {
        }

        template<class Alloc>
        heap(Container && cont, const Alloc & alloc, const Compare & comp)
        :   base(std::move(cont), alloc),
            comp_{comp}
        {
        }

        template<class Alloc>
        heap(Container && cont, const Alloc & alloc, Compare && comp)
        :   base(std::move(cont), alloc),
            comp_{std::move(comp)}
        {
        }

        template<class Alloc>
        heap(const heap & other, const Alloc & alloc)
        :   base(other.cont_, alloc),
            comp_{other.comp_}
        {
        }

        template<class Alloc>
        heap(heap && other, const Alloc & alloc)
        :   base(std::move(other.cont_), alloc),
            comp_{std::move(other.comp_)}
        {
        }

        reference top() { return this->front(); }
        const_reference top() const { return this->front(); }

        void push(const value_type & v)
        {
            this->push_back(v);
            push_heap(*this,this->comp_);
        }

        void push(value_type && v)
        {
            this->push_back(std::move(v));
            push_heap(*this,this->comp_);
        }

        template<typename... Args>
        reference emplace(Args && ...args)
        {
            auto v = this->emplace_back(std::forward<Args>(args)...);
            push_heap(*this,this->comp_);
            return v;
        }

        value_type pop()
        {
            auto v = this->top();
            pop_heap(*this,this->comp_);
            this->pop_back();
            return v;
        }

        iterator erase(const value_type & v)
        {
            auto r = equal_range(*this,v,this->comp_);
            return this->erase(r.begin(),r.end());
        }

    private:
        Compare comp_;
    };
}

#endif // ADS_HEAP_H
