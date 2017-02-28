#ifndef SUPER_SUB_TYPE_HH_INCLUDED
#define SUPER_SUB_TYPE_HH_INCLUDED

#include "Conversion.hh"

namespace csr
{
    template<typename A,typename B> struct super_sub_type
    {
        enum
        {
            result = conversion<const B*,const A*>::exists &&
                    !conversion<const A*,const void*>::same_type
        };
    };

    template<typename A,typename B> struct super_sub_type_strict
    {
        enum
        {
            result = conversion<const B*,const A*>::exists &&
                    !conversion<const A*,const B*>::same_type
        };
    };
}

#endif // SUPER_SUB_TYPE_HH_INCLUDED
