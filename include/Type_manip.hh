#ifndef TYPE_MANIP_HH_INCLUDED
#define TYPE_MANIP_HH_INCLUDED

//#include "Typelist.hh"

namespace csr
{
    template<int v>
    struct int2type
    {
        enum { value = v };
    };

    template<typename T>
    struct to_type
    {
        typedef T type;
    };

    template<bool flag,typename A,typename B> struct select
    {
        typedef A result;
    };

    template<typename A,typename B> struct select<false,A,B>
    {
        typedef B result;
    };

    template<typename T,typename U> struct same_type
    {
        enum { value = false };
    };

    template<typename T> struct same_type<T,T>
    {
        enum { value = true };
    };

    ////////////////////////////////////////////////////////////////////////////////
    // Helper types Small and Big - guarantee that sizeof(Small) < sizeof(Big)
    ////////////////////////////////////////////////////////////////////////////////

    namespace Private
    {
        template<typename T,typename U> struct conversion_helper
        {
            typedef char small;
            struct big { char bigger_than_one[2]; };
            static big   test(...);
            static small test(U);
            static T MakeT();
        };
    }

    ////////////////////////////////////////////////////////////////////////////////
    // class template conversion
    // Figures out the conversion relationships between two types
    // Invocations (T and U are types):
    // a) conversion<T,U>::exists
    // returns (at compile time) true if there is an implicit conversion from T
    // to U (example: Derived to Base)
    // b) conversion<T,U>::exists2way
    // returns (at compile time) true if there are both conversions from T
    // to U and from U to T (example: int to char and back)
    // c) conversion<T,U>::same_type
    // returns (at compile time) true if T and U represent the same type
    //
    // Caveat: might not work if T and U are in a private inheritance hierarchy.
    ////////////////////////////////////////////////////////////////////////////////

    template<typename T,typename U> class conversion
    {
        typedef Private::conversion_helper<T,U>    conversion_helper;
        typedef typename conversion_helper::small  small;

    public:
        enum
        {
            exists = sizeof(small)
                == sizeof((conversion_helper::test(conversion_helper::MakeT())))
        };

        enum { exists2way = exists && conversion<U,T>::exists };
        enum { same_type = false };
    };

    template<typename T>
    struct conversion<T,T>
    {
        enum { exists = true,exists2way = true,same_type = true };
    };

    template<typename T>
    struct conversion<void,T>
    {
        enum { exists = false,exists2way = false,same_type = false };
    };

    template<typename T>
    struct conversion<T,void>
    {
        enum { exists = false,exists2way = false,same_type = false };
    };

    template<> struct conversion<void,void>
    {
        enum { exists = true,exists2way = true,same_type = true };
    };

    template<typename T,typename U> struct super_sub_type
    {
        enum
        {
            result = (conversion<const volatile T*,const volatile U*>::exists
        && !conversion<const volatile T*,const volatile void*>::same_type)
        };
    };

    template<typename T,typename U>
    struct super_sub_type_strict
    {
        enum
        {
            result = (conversion<const volatile T*,const volatile U*>::exists
        && !conversion<const volatile T*,const volatile void*>::same_type
        && !conversion<const volatile U*,const volatile T*>::same_type)
        };
    };
}

#endif // TYPE_MANIP_HH_INCLUDED
