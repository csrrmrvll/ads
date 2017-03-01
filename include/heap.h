#ifndef ADS_HEAP_H
#define ADS_HEAP_H

#include <algorithm>
#include <utility>
#include <vector>
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
    public:
        using container_type = Container;
        using typename Container::iterator;
        using typename Container::const_iterator;
        using typename Container::reference;
        using typename Container::const_reference;
        using typename Container::size_type;
        using typename Container::value_type;

    //    heap()
    //    :   cont_{},
    //        comp_{}
    //    {
    //    }
    //
    //    explicit heap(const Compare & comp)
    //    :   cont_{},
    //        comp_{comp}
    //    {
    //    }
    //
    //    explicit heap(Compare && comp)
    //    :   cont_{},
    //        comp_{std::move(comp)}
    //    {
    //    }
    //
    //    explicit heap(const Container & cont, const Compare & comp)
    //    :   cont_{cont},
    //        comp_{comp}
    //    {
    //    }
    //
    //    explicit heap(const Container & cont, Compare && comp)
    //    :   cont_{cont},
    //        comp_{std::move(comp)}
    //    {
    //    }
    //
    //    explicit heap(Container && cont, const Compare & comp)
    //    :   cont_{std::move(cont)},
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
    //    :   cont_{begin(r),end(r)},
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
        :   cont_(alloc),
            comp_{comp}
        {
        }

        template<class Alloc>
        explicit heap(const Alloc & alloc, Compare && comp)
        :   cont_(alloc),
            comp_{std::move(comp)}
        {
        }

        template<class Alloc>
        heap(const Container & cont, const Alloc & alloc)
        :   cont_(cont, alloc),
            comp_{}
        {
        }

        template<class Alloc>
        heap(const Container & cont, const Alloc & alloc, const Compare & comp)
        :   cont_(cont, alloc),
            comp_{comp}
        {
        }

        template<class Alloc>
        heap(const Container && cont, const Alloc & alloc, Compare && comp)
        :   cont_(cont, alloc),
            comp_{std::move(comp)}
        {
        }

        template<class Alloc>
        heap(Container && cont, const Alloc & alloc, const Compare & comp)
        :   cont_(std::move(cont), alloc),
            comp_{comp}
        {
        }

        template<class Alloc>
        heap(Container && cont, const Alloc & alloc, Compare && comp)
        :   cont_(std::move(cont), alloc),
            comp_{std::move(comp)}
        {
        }

        template<class Alloc>
        heap(const heap & other, const Alloc & alloc)
        :   cont_(other.cont_, alloc),
            comp_{other.comp_}
        {
        }

        template<class Alloc>
        heap(heap && other, const Alloc & alloc)
        :   cont_(std::move(other.cont_), alloc),
            comp_{std::move(other.comp_)}
        {
        }

        reference top() { return this->cont_.front(); }
        const_reference top() const { return this->cont_.front(); }

        bool empty() const { return this->cont_.empty(); }

        size_type size() const { return this->cont_.size(); }

        void push(const value_type & v)
        {
            this->cont_.push_back(v);
            push_heap(begin(this->cont_),end(this->cont_),this->comp_);
        }

        void push(value_type && v)
        {
            this->cont_.push_back(std::move(v));
            push_heap(begin(this->cont_),end(this->cont_),this->comp_);
        }

        template<typename... Args>
        reference emplace(Args && ...args)
        {
            auto v = this->cont_.emplace_back(std::forward<Args>(args)...);
            push_heap(begin(this->cont_),end(this->cont_),this->comp_);
            return v;
        }

        value_type pop()
        {
            auto v = this->top();
            pop_heap(begin(this->cont_),end(this->cont_),this->comp_);
            this->cont_.pop_back();
            return v;
        }

        iterator erase(const value_type & v)
        {
            auto r = equal_range(this->cont_,v,this->comp_);
            return this->cont_.erase(r.begin(),r.end());
        }

    private:
        Container cont_;
        Compare comp_;
    };
}

#endif // ADS_HEAP_H
