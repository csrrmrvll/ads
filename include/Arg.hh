#ifndef ARG_HH_INCLUDED
#define ARG_HH_INCLUDED

namespace csr
{
//    template<size_t N = 50> struct arg;

    template<size_t N> struct arg
    :   public arg<N - 1>
    {
        enum { index = N };

        template
        <
            typename T01 = void_t,typename T02 = void_t,
            typename T03 = void_t,typename T04 = void_t,
            typename T05 = void_t,typename T06 = void_t,
            typename T07 = void_t,typename T08 = void_t,
            typename T09 = void_t,typename T10 = void_t,
            typename T11 = void_t,typename T12 = void_t,
            typename T13 = void_t,typename T14 = void_t,
            typename T15 = void_t,typename T16 = void_t,
            typename T17 = void_t,typename T18 = void_t,
            typename T19 = void_t,typename T20 = void_t,
            typename T21 = void_t,typename T22 = void_t,
            typename T23 = void_t,typename T24 = void_t,
            typename T25 = void_t,typename T26 = void_t,
            typename T27 = void_t,typename T28 = void_t,
            typename T29 = void_t,typename T30 = void_t,
            typename T31 = void_t,typename T32 = void_t,
            typename T33 = void_t,typename T34 = void_t,
            typename T35 = void_t,typename T36 = void_t,
            typename T37 = void_t,typename T38 = void_t,
            typename T39 = void_t,typename T40 = void_t,
            typename T41 = void_t,typename T42 = void_t,
            typename T43 = void_t,typename T44 = void_t,
            typename T45 = void_t,typename T46 = void_t,
            typename T47 = void_t,typename T48 = void_t,
            typename T49 = void_t,typename T50 = void_t
        >
        struct get
        {
            typedef typelist
                    <
                        T01,T02,T03,T04,T05,T06,T07,T08,T09,T10
                    >   list;
            typedef typename type_at<list,N>::result type;
        };
    };

    template<> struct arg<0>
    {
        enum { index = 0 };

        template<typename T01> struct get
        {
            typedef T01 type;
        };
    };

    typedef arg<0> _1;
    typedef arg<1> _2;
    typedef arg<2> _3;
    typedef arg<3> _4;
    typedef arg<4> _5;
    typedef arg<5> _6;
    typedef arg<6> _7;
    typedef arg<7> _8;
    typedef arg<8> _9;
    typedef arg<9> _10;
    typedef arg<0> _11;
    typedef arg<11> _12;
    typedef arg<12> _13;
    typedef arg<13> _14;
    typedef arg<14> _15;
    typedef arg<15> _16;
    typedef arg<16> _17;
    typedef arg<17> _18;
    typedef arg<18> _19;
    typedef arg<19> _20;
    typedef arg<20> _21;
    typedef arg<21> _22;
    typedef arg<22> _23;
    typedef arg<23> _24;
    typedef arg<24> _25;
    typedef arg<25> _26;
    typedef arg<26> _27;
    typedef arg<27> _28;
    typedef arg<28> _29;
    typedef arg<29> _30;
    typedef arg<30> _31;
    typedef arg<31> _32;
    typedef arg<32> _33;
    typedef arg<33> _34;
    typedef arg<34> _35;
    typedef arg<35> _36;
    typedef arg<36> _37;
    typedef arg<37> _38;
    typedef arg<38> _39;
    typedef arg<39> _40;
    typedef arg<40> _41;
    typedef arg<41> _42;
    typedef arg<42> _43;
    typedef arg<43> _44;
    typedef arg<44> _45;
    typedef arg<45> _46;
    typedef arg<46> _47;
    typedef arg<47> _48;
    typedef arg<48> _49;
    typedef arg<49> _50;
}

#endif // ARG_HH_INCLUDED
