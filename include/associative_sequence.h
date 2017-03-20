#ifndef ADS_ASSOCIATIVE_SEQUENCE_H
#define ADS_ASSOCIATIVE_SEQUENCE_H

#include <functional>
#include <utility>
#include "algorithm.h"
#include "sorted_sequence.h"
#include "range.h"

namespace ads
{
    namespace Private
    {
        template<typename Value,typename Compare>
        class associative_sequence_compare
        :   public Compare
        {
            using value = Value;
            using comp = Compare;
            using typename Compare::first_argument_type;
            using data = std::pair<first_argument_type,value>;

        public:
            associative_sequence_compare() = default;

            associative_sequence_compare(const comp & src)
            :   comp(src) { ; }

            bool operator()(const first_argument_type & lhs,
                            const first_argument_type & rhs) const
            {
                return comp::operator()(lhs,rhs);
            }

            bool operator()(const data & lhs,const data & rhs) const
            {
                return this(lhs.first,rhs.first);
            }

            bool operator()(const data & lhs,
                            const first_argument_type & rhs) const
            {
                return this(lhs.first,rhs);
            }

            bool operator()(const first_argument_type & lhs,
                            const data& rhs) const
            {
                return this(lhs,rhs.first);
            }
        };
    }

    template
    <
        typename Key,
        typename Value,
        typename Compare  = std::less<Key>
    >
    class associative_sequence
    :   private sorted_sequence<std::pair<Key,Value>>,
        private Private::associative_sequence_compare<Value,Compare>
    {
        using cont = sorted_sequence<std::pair<Key,Value>>;
        using cont::cnt;
        using comp = Private::associative_sequence_compare<Value,Compare>;

        constexpr comp & cmp()
        {
            return *this;
        }

        constexpr const comp & cmp() const
        {
            return *this;
        }

    public:
        using key_compare = Compare;
        using key_type = Key;
        using mapped_type = Value;
        using value_type = typename cont::value_type;
        using reference = typename cont::reference;
        using const_reference = typename cont::const_reference;
        using iterator = typename cont::iterator;
        using const_iterator = typename cont::const_iterator;
        using reverse_iterator = typename cont::reverse_iterator;
        using const_reverse_iterator = typename cont::const_reverse_iterator;
        using size_type = typename cont::size_type;
        using difference_type = typename cont::difference_type;
        using pointer = typename cont::pointer;
        using const_pointer = typename cont::const_pointer;

        class value_compare
        :   public std::binary_function<value_type,value_type,bool>,
            private key_compare
        {
            friend class associative_sequence;

        protected:
            value_compare(key_compare pred)
            :   key_compare(pred)
            {
            }

        public:
            bool operator()(const value_type & lhs,
                            const value_type & rhs) const
            {
                return key_compare::operator()(lhs.first,rhs.first);
            }
        };

        explicit associative_sequence(const key_compare & cmp = key_compare())
        :   cont(),
            comp(cmp)
        {
        }

        template<typename Iterator>
        associative_sequence(range<Iterator> && r,
                             const key_compare & cmp = key_compare())
        :   cont(r,cmp),
            comp(cmp)
        {
        }

        associative_sequence & operator=(const associative_sequence & rhs)
        {
            rhs.swap(*this);
            return *this;
        }

        // iterators:
        using cont::begin;
        using cont::end;
        using cont::rbegin;
        using cont::rend;

        // capacity:
        using cont::empty;
        using cont::size;
        using cont::max_size;

        mapped_type & operator[](const key_type & key)
        {
            return insert(value_type(key,mapped_type())).first->second;
        }

        // modifiers:
        std::pair<iterator,bool> insert(const value_type & val)
        {
            iterator i(this->lower_bound(val.first));
            if (i == this->end() || this->operator()(val.first,i->first))
            {
                i = cont::insert(i,val);
                return {i,false};
            }
            return {i,true};
        }

        iterator insert(iterator pos,const value_type & val)
        {
            if((pos == this->begin() || this->operator()(*(pos - 1),val))
               && (pos == this->end() || this->operator()(val, *pos)))
            {
                return cont::insert(pos,val);
            }
            return insert(val).first;
        }

        template<typename Iterator>
        void insert(range<Iterator> && r)
        {
            for (auto v : r)
            {
                this->insert(v);
            }
        }

        using cont::erase;

        size_type erase(const key_type & k)
        {
            iterator i(this->find(k));
            if (i == this->end())
            {
                return 0;
            }
            this->erase(i);
            return 1;
        }

        void erase(range<iterator> && r)
        {
            cont::erase(std::begin(r),std::end(r));
        }

        void swap(associative_sequence & other)
        {
            cont::swap(other);
            std::swap(cmp(),other.cmp());
        }

        using cont::clear;

        // observers:
        key_compare key_comp() const
        {
            return *this;
        }

        value_compare value_comp() const
        {
            return value_compare(this->key_comp());
        }

        // map operations:
        iterator find(const key_type & k)
        {
            iterator i(this->lower_bound(k));
            if (i != this->end() && !this->operator()(k,i->first))
            {
                return i;
            }
            return this->end();
        }

        const_iterator find(const key_type & k) const
        {
            const_iterator i(this->lower_bound(k));
            if (i != this->end() && !this->operator()(k,i->first))
            {
                return i;
            }
            return this->end();
        }

        size_type count(const key_type & k) const
        {
            return this->find(k) != this->end();
        }

        iterator lower_bound(const key_type & k)
        {
            return lower_bound(cnt(),k,cmp());
        }

        const_iterator lower_bound(const key_type & k) const
        {
            return lower_bound(cnt(),k,cmp());
        }

        iterator upper_bound(const key_type & k)
        {
            return upper_bound(cnt(),k,cmp());
        }

        const_iterator upper_bound(const key_type & k) const
        {
            return upper_bound(cnt(),k,cmp());
        }

        range<iterator> equal_range(const key_type & k)
        {
            return equal_range(cnt(),k,cmp());
        }

        range<const_iterator> equal_range(const key_type & k) const
        {
            return equal_range(cnt(),k,cmp());
        }

        template<typename K,typename V,typename C>
        friend bool operator==(const associative_sequence<K,V,C> & lhs,
                                const associative_sequence<K,V,C> & rhs);
        template<typename K,typename V,typename C>
        friend bool operator!=(const associative_sequence<K,V,C> & lhs,
                                const associative_sequence<K,V,C> & rhs);
        template<typename K,typename V,typename C>
        friend bool operator<(const associative_sequence<K,V,C> & lhs,
                                const associative_sequence<K,V,C> & rhs);
        template<typename K,typename V,typename C>
        friend bool operator<=(const associative_sequence<K,V,C> & lhs,
                                const associative_sequence<K,V,C> & rhs);
        template<typename K,typename V,typename C>
        friend bool operator>(const associative_sequence<K,V,C> & lhs,
                                const associative_sequence<K,V,C> & rhs);
        template<typename K,typename V,typename C>
        friend bool operator>=(const associative_sequence<K,V,C> & lhs,
                                const associative_sequence<K,V,C> & rhs);
    };

    // specialized algorithms:
    template<typename K,typename V,typename C>
    bool operator==(const associative_sequence<K,V,C> & lhs,
                            const associative_sequence<K,V,C> & rhs)
    {
        return lhs.cnt() == rhs.cnt();
    }

    template<typename K,typename V,typename C>
    bool operator!=(const associative_sequence<K,V,C> & lhs,
                            const associative_sequence<K,V,C> & rhs)
    {
        return !(lhs == rhs);
    }

    template<typename K,typename V,typename C>
    bool operator<(const associative_sequence<K,V,C> & lhs,
                            const associative_sequence<K,V,C> & rhs)
    {
        return lhs.cnt() < rhs.cnt();
    }

    template<typename K,typename V,typename C>
    bool operator<=(const associative_sequence<K,V,C> & lhs,
                            const associative_sequence<K,V,C> & rhs)
    {
        return lhs < rhs || lhs == rhs;
    }

    template<typename K,typename V,typename C>
    bool operator>(const associative_sequence<K,V,C> & lhs,
                            const associative_sequence<K,V,C> & rhs)
    {
        return !(lhs <= rhs);
    }

    template<typename K,typename V,typename C>
    bool operator>=(const associative_sequence<K,V,C> & lhs,
                            const associative_sequence<K,V,C> & rhs)
    {
        return !(lhs < rhs);
    }

    template<typename K,typename V,typename C>
    void swap(associative_sequence<K,V,C> & lhs,
              associative_sequence<K,V,C> & rhs)
    {
        lhs.swap(rhs);
    }
}

#endif // ADS_ASSOCIATIVE_SEQUENCE_H
