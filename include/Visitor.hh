#ifndef VISITOR_HH_INCLUDED
#define VISITOR_HH_INCLUDED

#include <stdexcept>

#include "Void_t.hh"
#include "Typelist.hh"

namespace csr
{
    struct base_visitor
    {
        virtual ~base_visitor() { ; }
    };

    template<typename T,typename R = void,bool IsConst = false>
    struct visitor;

    template<typename T,typename R>
    struct visitor<T,R,false>
    {
        typedef R return_type;
        typedef T param_type;
        virtual ~visitor() { ; }
        virtual return_type visit(param_type&) = 0;
    };

    template<typename T,typename R>
    struct visitor<T,R,true>
    {
        typedef R return_type;
        typedef const T param_type;
        virtual ~visitor() { ; }
        virtual return_type visit(param_type&) const = 0;
    };

    template<typename Head,typename Tail,typename R>
    struct visitor<typelist<Head,Tail>,R,false>
    :   public visitor<Head,R,false>,
        public visitor<Tail,R,false>
    {
        typedef R return_type;
       // using visitor<Head,R>::visit;
       // using visitor<Tail,R>::visit;
    };

    template<typename Head,typename R>
    struct visitor<typelist<Head,void_t>,R,false>
    :   public visitor<Head,R,false>
    {
        typedef R return_type;
        using visitor<Head,R,false>::visit;
    };

    template<typename Head,typename Tail,typename R>
    struct visitor<typelist<Head,Tail>,R,true>
    :   public visitor<Head,R,true>,
        public visitor<Tail,R,true>
    {
        typedef R return_type;
       // using visitor<Head,R>::visit;
       // using visitor<Tail,R>::visit;
    };

    template<typename Head,typename R>
    struct visitor<typelist<Head,void_t>,R,true>
    :   public visitor<Head,R,true>
    {
        typedef R return_type;
        using visitor<Head,R,true>::visit;
    };

    template<typename R = void>
    struct visitable_base
    {
        typedef R return_type;
        template<typename T>
        static return_type acceptImpl(T& visited, base_visitor& guest)
        {
            // Apply the Acyclic visitor
            if (visitor<T,R>* p = dynamic_cast<visitor<T,R>*>(&guest))
            {
                return p->visit(visited);
            }
            throw std::runtime_error("Unknown visitor classs!!!!!");
        }
        virtual ~visitable_base() { ; }
    };

    template<typename R = void,bool IsConst = false> struct visitable;

    template<typename R>
    struct visitable<R,false>
    :   public visitable_base<R>
    {
        typedef R return_type;
        virtual return_type accept(base_visitor&) = 0;
    };

    template<typename R>
    struct visitable<R,true>
    :   public visitable_base<R>
    {
        typedef R return_type;
        virtual ~visitable() { ; }
        virtual return_type accept(base_visitor&) const = 0;
    };

#define MAKE_VISITABLE() \
    virtual return_type accept(::csr::base_visitor& guest) \
    { return acceptImpl(*this, guest); }

#define MAKE_CONST_VISITABLE() \
    virtual return_type accept(::csr::base_visitor& guest) const \
    { return acceptImpl(*this, guest); }

    template<typename T,typename R = void,bool IsConst = false>
    struct cyclic_visitor;

    template<typename TList,typename R>
    struct cyclic_visitor<TList,R,false>
    :   public visitor<TList,R,false>
    {
        typedef R return_type;
        // using visitor<TList, R>::visit;

        template<typename Visited>
        return_type generic_visit(Visited& host)
        {
            visitor<Visited,return_type>& subObj = *this;
            return subObj.visit(host);
        }
    };

    template<typename TList,typename R>
    struct cyclic_visitor<TList,R,true>
    :   public visitor<TList,R,true>
    {
        typedef R return_type;
        // using visitor<TList, R>::visit;

        template<typename Visited>
        return_type generic_visit(Visited& host) const
        {
            visitor<Visited,return_type>& subObj = *this;
            return subObj.visit(host);
        }
    };

    template<typename R = void,bool IsConst = false> class cyclic_visitable;

    template<typename R>
    class cyclic_visitable<R,false>
    {
    public:
        typedef cyclic_visitable<R,false> this_t;
        typedef R return_type;
        typedef cyclic_visitor<this_t,return_type,false> visitor_type;
        virtual ~cyclic_visitable() { ; }
    };

    template<typename R>
    class cyclic_visitable<R,true>
    {
    public:
        typedef cyclic_visitable<R,true> this_t;
        typedef R return_type;
        typedef cyclic_visitor<this_t,return_type,true> visitor_type;
        virtual ~cyclic_visitable() { ; }
    };

#define MAKE_CYCLIC_VISITABLE(SomeVisitor) \
    virtual SomeVisitor::return_type accept(SomeVisitor& guest) \
    { return guest.generic_visit(*this); }
}

#endif // VISITOR_HH_INCLUDED
