#ifndef PLACEHOLDERS_HH_INCLUDED
#define PLACEHOLDERS_HH_INCLUDED

#include "Void_t.hh"

namespace csr
{
    template<int> struct arg;

    template<> struct arg<1>
    {
        template
        <
            typename A1,typename A2 = void_t,typename A3 = void_t,
            typename A4 = void_t,typename A5 = void_t,typename A6 = void_t,
            typename A7 = void_t,typename A8 = void_t,typename A9 = void_t,
            typename A10 = void_t
        >
        struct apply
        {
            typedef A1 type;
        };
    };
    typedef arg<1> _1;

    template<> struct arg<2>
    {
        template
        <
            typename A1,typename A2,typename A3 = void_t,
            typename A4 = void_t,typename A5 = void_t,typename A6 = void_t,
            typename A7 = void_t,typename A8 = void_t,typename A9 = void_t,
            typename A10 = void_t
        >
        struct apply
        {
            typedef A2 type;
        };
    };
    typedef arg<2> _2;

    template<> struct arg<3>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4 = void_t,
            typename A5 = void_t,typename A6 = void_t,typename A7 = void_t,
            typename A8 = void_t,typename A9 = void_t,typename A10 = void_t
        >
        struct apply
        {
            typedef A3 type;
        };
    };
    typedef arg<3> _3;

    template<> struct arg<4>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,
            typename A5 = void_t,typename A6 = void_t,typename A7 = void_t,
            typename A8 = void_t,typename A9 = void_t,typename A10 = void_t
        >
        struct apply
        {
            typedef A4 type;
        };
    };
    typedef arg<4> _4;

    template<> struct arg<5>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,typename A5,
            typename A6 = void_t,typename A7 = void_t,typename A8 = void_t,
            typename A9 = void_t,typename A10 = void_t
        >
        struct apply
        {
            typedef A5 type;
        };
    };
    typedef arg<5> _5;

    template<> struct arg<6>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,typename A5,
            typename A6,typename A7 = void_t,typename A8 = void_t,
            typename A9 = void_t,typename A10 = void_t
        >
        struct apply
        {
            typedef A6 type;
        };
    };
    typedef arg<6> _6;

    template<> struct arg<7>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,typename A5,
            typename A6,typename A7,typename A8 = void_t,typename A9 = void_t,
            typename A10 = void_t
        >
        struct apply
        {
            typedef A7 type;
        };
    };
    typedef arg<7> _7;

    template<> struct arg<8>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,typename A5,
            typename A6,typename A7,typename A8,typename A9 = void_t,
            typename A10 = void_t
        >
        struct apply
        {
            typedef A8 type;
        };
    };
    typedef arg<8> _8;

    template<> struct arg<9>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,typename A5,
            typename A6,typename A7,typename A8,typename A9,
            typename A10 = void_t
        >
        struct apply
        {
            typedef A9 type;
        };
    };
    typedef arg<9> _9;

    template<> struct arg<10>
    {
        template
        <
            typename A1,typename A2,typename A3,typename A4,typename A5,
            typename A6,typename A7,typename A8,typename A9,typename A10
        >
        struct apply
        {
            typedef A10 type;
        };
    };
    typedef arg<10> _10;
}

#endif // PLACEHOLDERS_HH_INCLUDED
