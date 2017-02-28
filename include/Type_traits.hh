#ifndef TYPE_TRAITS_HH_INCLUDED
#define TYPE_TRAITS_HH_INCLUDED

#include "Typelist.hh"
#include "Typelist_operations.hh"
#include "Void_t.hh"

namespace csr
{
/**
 *  custom tests: should you want to provide your own types then you must
 *  specialize these for them.
 */
    template<typename T>
    struct is_custom_enum
    {
        enum { value = 0 };
    };

    template<typename T>
    struct is_custom_POD
    {
        enum { value = 0 };
    };

    template<typename T>
    struct is_custom_unsigned_int
    {
        enum { value = 0 };
    };

    template<typename T>
    struct is_custom_signed_int
    {
        enum { value = 0 };
    };

    template<typename T>
    struct is_custom_float
    {
        enum { value = 0 };
    };

    namespace Private
    {
        typedef typelist<unsigned char,unsigned short int,
                        unsigned int,unsigned long int> std_unsigned_ints;

        typedef typelist<signed char,short int,
                                        int,long int> std_signed_ints;

        typedef typelist<bool,char,wchar_t> std_other_ints;

        typedef typelist<float,double,long double> std_floats;

        template<typename U> struct add_reference
        {
            typedef U& result;
        };

        template<typename U> struct add_reference<U&>
        {
            typedef U& result;
        };

        template<> struct add_reference<void>
        {
            typedef void_t result;
        };
    }

    template<typename T> class type_traits
    {
    private:
        template<bool b> struct base_traits_select { enum { result = b }; }; // impl detail

        template<bool b,typename U = void_t> struct base_traits // impl detail
        :   public base_traits_select<b>
        {
            enum { result = base_traits_select<b>::result };
            typedef U type;
        };

        template<typename U> struct pointer_traits
        :   public base_traits<false> {};

        template<typename U> struct pointer_traits<U*>
        :   public base_traits<true,U> {};

        template<typename U> struct reference_traits
        :   public base_traits<false,U> {};

        template<typename U> struct reference_traits<U&>
        :   public base_traits<true,U> {};

        template<typename U> struct ptr_to_mem_traits
        :   public base_traits_select<false> {};

        template<typename U,typename V> struct ptr_to_mem_traits<U V::*>
        :   public base_traits_select<true> {};

        template<bool b,typename U> struct unqualify_base // impl detail
        {
            typedef U result;
            enum { is_qualified = b };
        };

        template<typename U> struct unqualify
        :   public unqualify_base<false,U> {};

        template<typename U> struct unqualify<const U>
        :   public unqualify_base<true,U> {};

        template<typename U> struct unqualify<volatile U>
        :   public unqualify_base<true,U> {};

        template<typename U> class unconst
        {
            typedef unqualify<U> unqualify_type;

        public:
            typedef typename unqualify_type::result result;
            enum { is_const = unqualify_type::is_qualified };
        };

        template<typename U> class unvolatile
        {
            typedef unqualify<U> unqualify_type;

        public:
            typedef typename unqualify_type::result result;
            enum { is_volatile = unqualify_type::is_qualified };
        };

    public:
        enum { is_pointer = pointer_traits<T>::result };
        typedef typename pointer_traits<T>::type pointee_type;

        enum { is_reference = reference_traits<T>::result };
        typedef typename reference_traits<T>::type referred_type;

        enum { is_ptr_to_mem = ptr_to_mem_traits<T>::result };

        enum { is_std_unsigned_int
                        = index_of<Private::std_unsigned_ints,T>::value >= 0 };

        enum { is_std_signed_int
                        = index_of<Private::std_signed_ints,T>::value >= 0 };

        enum { is_std_integral = is_std_unsigned_int || is_std_signed_int
                        || index_of<Private::std_other_ints,T>::value >= 0 };

        enum { is_std_float = index_of<Private::std_floats,T>::value >= 0 };

        enum { is_std_arithmetic = is_std_integral || is_std_float };

        enum { is_std_fundamental = is_std_arithmetic || is_std_float
                                    || conversion<T,void>::same_type };

        enum { is_unsigned_int = is_std_unsigned_int
                                || is_custom_unsigned_int<T>::value };

        enum { is_signed_int = is_std_signed_int
                                || is_custom_signed_int<T>::value };

        enum { is_integral
                        = is_std_integral || is_unsigned_int || is_signed_int };

        enum { is_float = is_std_float || is_custom_float<T>::value };

        enum { is_arithmetic = is_integral || is_float };

        enum { is_fundamental
                        = is_std_fundamental || is_arithmetic || is_float };

        typedef typename select
            <
                is_std_arithmetic || is_pointer|| is_ptr_to_mem,
                T,
                typename Private::add_reference<T>::result
            >::result parameter_type;

        enum { is_const = unconst<T>::is_const };
        typedef typename unconst<T>::result non_const_type;

        enum { is_volatile = unvolatile<T>::is_volatile };
        typedef typename unvolatile<T>::result non_volatile_type;

        typedef typename unqualify<T>::result unqualified_type;
    };
}

#endif // TYPE_TRAITS_HH_INCLUDED
