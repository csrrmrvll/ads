#ifndef ASSOC_VECTOR_HH_INCLUDED
#define ASSOC_VECTOR_HH_INCLUDED

#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include "range.h"

namespace ads
{
////////////////////////////////////////////////////////////////////////////////
// class template assoc_vector_compare
// Used by assoc_vector
////////////////////////////////////////////////////////////////////////////////

    namespace Private
    {
        template<typename Value,typename Comp>
        class assoc_vector_compare
        :   public Comp
        {
            typedef Value                                value;
            typedef Comp                                 compare_func;
            typedef typename Comp::first_argument_type  first_argument_type;
            typedef std::pair<first_argument_type,value> data;

        public:
            assoc_vector_compare() { ; }

            assoc_vector_compare(const compare_func& src)
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

////////////////////////////////////////////////////////////////////////////////
// class template assoc_vector
// An associative vector built as a syntactic drop-in replacement for std::map
// BEWARE: assoc_vector doesn't respect all map's guarantees,the most important
// being:
// * iterators are invalidated by insert and erase operations
// * the complexity of insert/erase is O(N) not O(log N)
// * value_type is std::pair<Key,Value> not std::pair<const Key,Value>
// * iterators are random
////////////////////////////////////////////////////////////////////////////////

    template
    <
        typename Key,
        typename Value,
        typename Comp  = std::less<Key>,
        typename Alloc = std::allocator<std::pair<Key,Value> >
    >
    class sorted_vector
    :   private std::vector<std::pair<Key,Value>,Alloc>,
        private Private::assoc_vector_compare<Value,Comp>
    {
        typedef std::vector<std::pair<Key,Value>,Alloc>     base;
        typedef Private::assoc_vector_compare<Value,Comp>   compare_func;

    public:
        typedef Key                                      key_type;
        typedef Value                                    mapped_type;
        typedef typename base::value_type               value_type;
        typedef Comp                                     key_compare;
        typedef Alloc                                    allocator_type;
        typedef typename Alloc::reference               reference;
        typedef typename Alloc::const_reference         const_reference;
        typedef typename base::iterator                 iterator;
        typedef typename base::const_iterator           const_iterator;
        typedef typename base::size_type                size_type;
        typedef typename base::difference_type          difference_type;
        typedef typename Alloc::pointer                 pointer;
        typedef typename Alloc::const_pointer           const_pointer;
        typedef typename base::reverse_iterator         reverse_iterator;
        typedef typename base::const_reverse_iterator   const_reverse_iterator;

        class value_compare
        :   public std::binary_function<value_type,value_type,bool>,
            private key_compare
        {
            friend class sorted_vector;

        protected:
            value_compare(key_compare pred)
            :   key_compare(pred) { ; }

        public:
            bool operator()(const value_type& lhs,
                                const value_type& rhs) const
            { return key_compare::operator()(lhs.first,rhs.first); }
        };

        explicit sorted_vector(const key_compare& comp = key_compare(),
                                const allocator_type& alloc = allocator_type())
        : base(alloc),compare_func(comp) { ; }

        template<typename InputIterator>
        sorted_vector(InputIterator first,InputIterator last,
                        const key_compare& comp = key_compare(),
                        const allocator_type& alloc = allocator_type())
        :   base(first,last,alloc),compare_func(comp)
        {
            compare_func& me = *this;
            std::sort(this->begin(),this->end(),me);
        }

        sorted_vector& operator=(const sorted_vector& rhs)
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
            return std::make_pair(i,!found);
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
        { for (   ; first != last; ++first) { this->insert(*first); } }

        void erase(iterator pos)
        { base::erase(pos); }

        size_type erase(const key_type& k)
        {
            iterator i(this->find(k));
            if (i == this->end())
                return 0;

            this->erase(i);
            return 1;
        }

        void erase(iterator first,iterator last)
        { base::erase(first,last); }

        void swap(sorted_vector& other)
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
                i = this->end();
            }
            return i;
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
        friend bool operator==(const sorted_vector<K1, V1, C1, A1>& lhs,
                                const sorted_vector<K1, V1, C1, A1>& rhs);

        bool operator<(const sorted_vector& rhs) const
        {
            const base& me = *this;
            const base& yo = rhs;
            return me < yo;
        }

        template <class K1, class V1, class C1, class A1>
        friend bool operator!=(const sorted_vector<K1, V1, C1, A1>& lhs,
                                const sorted_vector<K1, V1, C1, A1>& rhs);

        template <class K1, class V1, class C1, class A1>
        friend bool operator>(const sorted_vector<K1, V1, C1, A1>& lhs,
                                const sorted_vector<K1, V1, C1, A1>& rhs);

        template <class K1, class V1, class C1, class A1>
        friend bool operator>=(const sorted_vector<K1, V1, C1, A1>& lhs,
                                const sorted_vector<K1, V1, C1, A1>& rhs);

        template <class K1, class V1, class C1, class A1>
        friend bool operator<=(const sorted_vector<K1, V1, C1, A1>& lhs,
                                const sorted_vector<K1, V1, C1, A1>& rhs);
    };

    template <class K, class V, class C, class A>
    inline bool operator==(const sorted_vector<K, V, C, A>& lhs,
                            const sorted_vector<K, V, C, A>& rhs)
    {
        const std::vector<std::pair<K, V>, A>& me = lhs;
        return me == rhs;
    }

    template <class K, class V, class C, class A>
    inline bool operator!=(const sorted_vector<K, V, C, A>& lhs,
                            const sorted_vector<K, V, C, A>& rhs)
    { return !(lhs == rhs); }

    template <class K, class V, class C, class A>
    inline bool operator>(const sorted_vector<K, V, C, A>& lhs,
                            const sorted_vector<K, V, C, A>& rhs)
    { return rhs < lhs; }

    template <class K, class V, class C, class A>
    inline bool operator>=(const sorted_vector<K, V, C, A>& lhs,
                            const sorted_vector<K, V, C, A>& rhs)
    { return !(lhs < rhs); }

    template <class K, class V, class C, class A>
    inline bool operator<=(const sorted_vector<K, V, C, A>& lhs,
                            const sorted_vector<K, V, C, A>& rhs)
    { return !(rhs < lhs); }

    // specialized algorithms:
    template<typename Key,typename Value,typename Comp,typename Alloc>
    void swap(sorted_vector<Key,Value,Comp,Alloc>& lhs,
              sorted_vector<Key,Value,Comp,Alloc>& rhs)
    { lhs.swap(rhs); }

}

#endif // ASSOC_VECTOR_HH_INCLUDED
