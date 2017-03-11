#ifndef ADS_ASSOCIATIVE_SEQUENCE_H
#define ADS_ASSOCIATIVE_SEQUENCE_H

#include <functional>
#include <vector>
#include <utility>
#include "algorithm.h"
#include "range.h"

namespace ads
{
    namespace Private
    {
        template<typename Value,typename Comp>
        class associative_sequence_compare
        :   public Comp
        {
            using value = Value;
            using compare_func = Comp;
            using typename Comp::first_argument_type;
            using data = std::pair<first_argument_type,value>;

        public:
            associative_sequence_compare() { ; }

            associative_sequence_compare(const compare_func& src)
            :   compare_func(src) { ; }

            bool operator()(const first_argument_type& lhs,
                                const first_argument_type& rhs) const
            { return compare_func::operator()(lhs,rhs); }

            bool operator()(const data& lhs,const data& rhs) const
            { return operator()(lhs.first,rhs.first); }

            bool operator()(const data& lhs,
                                const first_argument_type& rhs) const
            { return operator()(lhs.first,rhs); }

            bool operator()(const first_argument_type& lhs,
                                const data& rhs) const
            { return operator()(lhs,rhs.first); }
        };
    }

    template
    <
        typename Key,
        typename Value,
        typename Comp  = std::less<Key>,
        typename Alloc = std::allocator<std::pair<Key,Value>>
    >
    class associative_sequence
    :   private std::vector<std::pair<Key,Value>,Alloc>,
        private Private::associative_sequence_compare<Value,Comp>
    {
        using base = std::vector<std::pair<Key,Value>,Alloc>;
        using compare_func = Private::associative_sequence_compare<Value,Comp>;

    public:
        using key_compare = Comp;
        using key_type = Key;
        using mapped_type = Value;
        using typename base::value_type;
        using typename base::allocator_type;
        using typename base::reference;
        using typename base::const_reference;
        using typename base::iterator;
        using typename base::const_iterator;
        using typename base::size_type;
        using typename base::difference_type;
        using typename base::pointer;
        using typename base::const_pointer;
        using typename base::reverse_iterator;
        using typename base::const_reverse_iterator;

        class value_compare
        :   public std::binary_function<value_type,value_type,bool>,
            private key_compare
        {
            friend class associative_sequence;

        protected:
            value_compare(key_compare pred)
            :   key_compare(pred) { ; }

        public:
            bool operator()(const value_type& lhs,
                                const value_type& rhs) const
            { return key_compare::operator()(lhs.first,rhs.first); }
        };

        explicit associative_sequence(const key_compare& comp = key_compare(),
                                const allocator_type& alloc = allocator_type())
        :   base(alloc),compare_func(comp) { ; }

        template<typename InputIterator>
        associative_sequence(InputIterator first,InputIterator last,
                        const key_compare& comp = key_compare(),
                        const allocator_type& alloc = allocator_type())
        :   base(first,last,alloc),compare_func(comp)
        {
            compare_func& me = *this;
            std::sort(this->begin(),this->end(),me);
        }

        associative_sequence& operator=(const associative_sequence& rhs)
        {
            rhs.swap(*this);
            return *this;
        }

        // iterators:
        using base::begin;
        using base::end;
        using base::rbegin;
        using base::rend;

        // capacity:
        using base::empty;
        using base::size;
        using base::max_size;

        mapped_type& operator[](const key_type& key)
        { return insert(value_type(key,mapped_type())).first->second; }

        // modifiers:
        std::pair<iterator,bool> insert(const value_type& val)
        {
            bool found = true;
            iterator i(this->lower_bound(val.first));

            if (i == this->end() || this->operator()(val.first,i->first))
            {
                i = base::insert(i,val);
                found = false;
            }
            return std::make_pair(i,found);
        }

        iterator insert(iterator pos,const value_type& val)
        {
            if((pos == this->begin() || this->operator()(*(pos - 1),val))
               && (pos == this->end() || this->operator()(val, *pos)))
            {
                return base::insert(pos,val);
            }
            return insert(val).first;
        }

        template<typename InputIterator>
        void insert(InputIterator first,InputIterator last)
        { for (auto v : make_range(first, last)) { this->insert(v); } }

        void erase(iterator pos)
        { base::erase(pos); }

        size_type erase(const key_type& k)
        {
            iterator i(this->find(k));
            if (i == this->end())
            {
                return 0;
            }
            this->erase(i);
            return 1;
        }

        void erase(iterator first,iterator last)
        { base::erase(first,last); }

        void swap(associative_sequence& other)
        {
            base::swap(other);
            compare_func    &me = *this,
                            &rhs = other;
            std::swap(me,rhs);
        }

        void clear()
        { base::clear(); }

        // observers:
        key_compare key_comp() const
        { return *this; }

        value_compare value_comp() const
        {
            const key_compare& comp = *this;
            return value_compare(comp);
        }

        // map operations:
        iterator find(const key_type& k)
        {
            iterator i(this->lower_bound(k));
            if (i != this->end() && this->operator()(k,i->first))
            {
                i = this->end();
            }
            return i;
        }

        const_iterator find(const key_type& k) const
        {
            const_iterator i(this->lower_bound(k));
            if (i != this->end() && this->operator()(k,i->first))
            {
                return i;
            }
            return this->end();
        }

        size_type count(const key_type& k) const
        { return std::find(k) != this->end(); }

        iterator lower_bound(const key_type& k)
        {
            compare_func& me = *this;
            return std::lower_bound(this->begin(),this->end(),k,me);
        }

        const_iterator lower_bound(const key_type& k) const
        {
            const compare_func& me = *this;
            return std::lower_bound(this->begin(),this->end(),k,me);
        }

        iterator upper_bound(const key_type& k)
        {
            compare_func& me = *this;
            return std::upper_bound(this->begin(),this->end(),k,me);
        }

        const_iterator upper_bound(const key_type& k) const
        {
            const compare_func& me = *this;
            return std::upper_bound(this->begin(),this->end(),k,me);
        }

        std::pair<iterator,iterator> equal_range(const key_type& k)
        {
            compare_func& me = *this;
            return std::equal_range(this->begin(),this->end(),k,me);
        }

        std::pair<const_iterator,const_iterator> equal_range(
                                                    const key_type& k) const
        {
            const compare_func& me = *this;
            return std::equal_range(this->begin(),this->end(),k,me);
        }

        template <class K1, class V1, class C1, class A1>
        friend bool operator==(const associative_sequence<K1, V1, C1, A1>& lhs,
                                const associative_sequence<K1, V1, C1, A1>& rhs)
        {
            const base  & a = lhs,
                        & b = rhs;
            return a == b;
        }


        template <class K1, class V1, class C1, class A1>
        friend bool operator!=(const associative_sequence<K1, V1, C1, A1>& lhs,
                                const associative_sequence<K1, V1, C1, A1>& rhs)
        {
            return !(lhs == rhs);
        }

        template <class K1, class V1, class C1, class A1>
        friend bool operator<(const associative_sequence<K1, V1, C1, A1>& lhs,
                                const associative_sequence<K1, V1, C1, A1>& rhs)
        {
            const base  & a = lhs,
                        & b = rhs;
            return a < b;
        }

        template <class K1, class V1, class C1, class A1>
        friend bool operator<=(const associative_sequence<K1, V1, C1, A1>& lhs,
                                const associative_sequence<K1, V1, C1, A1>& rhs)
        {
            return lhs < rhs || lhs == rhs;
        }

        template <class K1, class V1, class C1, class A1>
        friend bool operator>(const associative_sequence<K1, V1, C1, A1>& lhs,
                                const associative_sequence<K1, V1, C1, A1>& rhs)
        {
            return !(lhs <= rhs);
        }

        template <class K1, class V1, class C1, class A1>
        friend bool operator>=(const associative_sequence<K1, V1, C1, A1>& lhs,
                                const associative_sequence<K1, V1, C1, A1>& rhs)
        {
            return !(lhs < rhs);
        }
    };

    // specialized algorithms:
    template<typename Key,typename Value,typename Comp,typename Alloc>
    void swap(associative_sequence<Key,Value,Comp,Alloc>& lhs,
              associative_sequence<Key,Value,Comp,Alloc>& rhs)
    { lhs.swap(rhs); }
}

#endif // ADS_ASSOCIATIVE_SEQUENCE_H
