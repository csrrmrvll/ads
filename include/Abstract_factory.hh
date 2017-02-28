#ifndef ABSTRACT_FACTORY_HH_INCLUDED
#define ABSTRACT_FACTORY_HH_INCLUDED

#include "Typelist.hh"
#include "Type_manip.hh"
#include "Hierarchy_generators.hh"

#include <cassert>

namespace csr
{
////////////////////////////////////////////////////////////////////////////////
// class template abstract_unit
// The building block of an Abstract Factory
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    struct abstract_unit
    {
        virtual T* do_create(to_type<T>) = 0;
        virtual ~abstract_unit() { ; }
    };

////////////////////////////////////////////////////////////////////////////////
// class template abstract_factory
// Defines an Abstract Factory interface starting from a typelist
////////////////////////////////////////////////////////////////////////////////
    template
    <
        typename TList,
        template<typename> class Unit = abstract_unit
    >
    struct abstract_factory
    :   public generate_scatter_hierarchy<TList,Unit>
    {
        typedef TList products_list;

        template<typename T> T* create()
        {
            Unit<T>& unit = *this;
            return unit.do_create(to_type<T>());
        }
    };

////////////////////////////////////////////////////////////////////////////////
// class template op_new_unit
// Creates an object by invoking the new operator
////////////////////////////////////////////////////////////////////////////////

    template<typename ConcreteProduct,typename Base>
    class op_new_unit
    :   public Base
    {
        typedef typename Base::products_list base_products_list;

    protected:
        typedef typename base_products_list::tail products_list;

    public:
        typedef typename base_products_list::head AbstractProduct;

        ConcreteProduct* do_create(to_type<AbstractProduct>)
        {
            return new ConcreteProduct;
        }
    };

////////////////////////////////////////////////////////////////////////////////
// class template prototype_unit
// Creates an object by cloning a prototype
// There is a difference between the implementation herein and the one described
// in the book: get_prototype and set_prototype use the helper friend
// functions do_get_prototype and do_set_prototype. The friend functions avoid
// name hiding issues. Plus,get_prototype takes a reference to pointer
// instead of returning the pointer by value.
////////////////////////////////////////////////////////////////////////////////

    template<typename ConcreteProduct,typename Base>
    class prototype_unit
    :   public Base
    {
        typedef typename Base::products_list base_products_list;

    protected:
        typedef typename base_products_list::tail products_list;

    public:
        typedef typename base_products_list::head AbstractProduct;

        prototype_unit(AbstractProduct* p = 0)
        :   pPrototype_(p)
        { ; }

        template<typename CP,typename Base1>
        friend void do_get_prototype(const prototype_unit<CP,Base1>& me,
                           typename Base1::products_list::head*& pPrototype);

        template<typename CP,typename Base1>
        friend void do_set_prototype(prototype_unit<CP,Base1>& me,
                                   typename Base1::products_list::head* pObj);

        template<typename U>
        void get_prototype(U*& p)
        { return do_get_prototype(*this,p); }

        template<typename U>
        void set_prototype(U* pObj)
        { do_set_prototype(*this,pObj); }

        AbstractProduct* do_create(to_type<AbstractProduct>)
        {
            assert(pPrototype_);
            return pPrototype_->clone();
        }

    private:
        AbstractProduct* pPrototype_;
    };

    template<typename CP,typename Base>
    inline void do_get_prototype(const prototype_unit<CP,Base>& me,
                           typename Base::products_list::head*& pPrototype)
    { pPrototype = me.pPrototype_; }

    template<typename CP,typename Base>
    inline void do_set_prototype(prototype_unit<CP,Base>& me,
                               typename Base::products_list::head* pObj)
    { me.pPrototype_ = pObj; }

////////////////////////////////////////////////////////////////////////////////
// class template concrete_factory
// Implements an abstract_factory interface
////////////////////////////////////////////////////////////////////////////////

    template
    <
        typename AbstractFact,
        template<typename,typename> class Creator = op_new_unit,
        typename TList = typename AbstractFact::products_list
    >
    class concrete_factory
    :   public generate_linear_hierarchy
                <
                    typename reverse<TList>::result,
                    Creator,
                    AbstractFact
                >
    {
    public:
        typedef typename AbstractFact::products_list products_list;
        typedef TList concrete_products_list;
    };
}

#endif // ABSTRACT_FACTORY_HH_INCLUDED
