#ifndef PARMS_LIST_HH_INCLUDED
#define PARMS_LIST_HH_INCLUDED

#include "Typelist_operations.hh"

namespace csr
{
    template<typename TypeList,size_t N> struct parms_list_impl;

    template<typename TypeList> struct parms_list_impl<TypeList,0>
    {
        typedef typename type_at<TypeList,0>::result parm01;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,1>
    :   public parms_list_impl<TypeList,0>
    {
        typedef typename type_at<TypeList,1>::result parm02;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,2>
    :   public parms_list_impl<TypeList,1>
    {
        typedef typename type_at<TypeList,2>::result parm03;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,3>
    :   public parms_list_impl<TypeList,2>
    {
        typedef typename type_at<TypeList,3>::result parm04;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,4>
    :   public parms_list_impl<TypeList,3>
    {
        typedef typename type_at<TypeList,4>::result parm05;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,5>
    :   public parms_list_impl<TypeList,4>
    {
        typedef typename type_at<TypeList,5>::result parm06;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,6>
    :   public parms_list_impl<TypeList,5>
    {
        typedef typename type_at<TypeList,6>::result parm07;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,7>
    :   public parms_list_impl<TypeList,6>
    {
        typedef typename type_at<TypeList,7>::result parm08;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,8>
    :   public parms_list_impl<TypeList,7>
    {
        typedef typename type_at<TypeList,8>::result parm09;
    };

    template<typename TypeList> struct parms_list_impl<TypeList,9>
    :   public parms_list_impl<TypeList,8>
    {
        typedef typename type_at<TypeList,9>::result parm10;
    };

#ifdef GEN_PARM_NAME
#undef GEN_PARM_NAME
#endif

#define GEN_PARM_NAME(n) parm##n

    template<typename TypeList,size_t N> struct parms_list_impl
    :   public parms_list_impl<TypeList,N - 1>
    {
        typedef typename type_at<TypeList,N>::result GEN_PARM_NAME(N);
    };

#undef GEN_PARM_NAME

    template
    <
        typename T01 = void_t,typename T02 = void_t,
        typename T03 = void_t,typename T04 = void_t,
        typename T05 = void_t,typename T06 = void_t,
        typename T07 = void_t,typename T08 = void_t,
        typename T09 = void_t,typename T10 = void_t
    >
    struct parms_list
    :   public parms_list_impl
                <
                    typelist<T01,T02,T03,T04,T05,T06,T07,T08,T09,T10>,
                    length
                    <
                        typelist<T01,T02,T03,T04,T05,T06,T07,T08,T09,T10>
                    >::value
                >
    {
    };
}

#endif // PARMS_LIST_HH_INCLUDED
