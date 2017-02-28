#ifndef PARAMS_LIST_HH_INCLUDED
#define PARAMS_LIST_HH_INCLUDED

#include "Typelist.hh"
#include "Typelist_operations.hh"

#ifdef PARM
#undef PARM
#endif

#define PARM(n) parm##n

namespace csr
{
template<size_t N>
struct params_list
{
    template<typename TypeList> struct index; // decl

    template
    <
        typename P01,typename P02,typename P03,typename P04,typename P05,
        typename P06,typename P07,typename P08,typename P09,typename P10,
        typename P11,typename P12,typename P13,typename P14,typename P15,
        typename P16,typename P17,typename P18,typename P19,typename P20,
        typename P21,typename P22,typename P23,typename P24,typename P25,
        typename P26,typename P27,typename P28,typename P29,typename P30,
        typename P31,typename P32,typename P33,typename P34,typename P35,
        typename P36,typename P37,typename P38,typename P39,typename P40,
        typename P41,typename P42,typename P43,typename P44,typename P45,
        typename P46,typename P47,typename P48,typename P49,typename P50
    >
    struct index // the only specialization provided
            <
                typelist
                <
                    P01,P02,P03,P04,P05,P06,P07,P08,P09,P10,P11,P12,
                    P13,P14,P15,P16,P17,P18,P19,P20,P21,P22,P23,P24,
                    P25,P26,P27,P28,P29,P30,P31,P32,P33,P34,P35,P36,
                    P37,P38,P39,P40,P41,P42,P43,P44,P45,P46,P47,P48,
                    P49,P50
                >
            >
    {
        typedef typelist
                    <
                        P01,P02,P03,P04,P05,P06,P07,P08,P09,P10,P11,P12,
                        P13,P14,P15,P16,P17,P18,P19,P20,P21,P22,P23,P24,
                        P25,P26,P27,P28,P29,P30,P31,P32,P33,P34,P35,P36,
                        P37,P38,P39,P40,P41,P42,P43,P44,P45,P46,P47,P48,
                        P49,P50
                    > types;
        typedef typename type_at<types,N>::result PARM(N);
    };
};
}

#undef PARM

#endif // PARAMS_LIST_HH_INCLUDED
