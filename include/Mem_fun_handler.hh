#ifndef MEM_FUN_HANDLER_HH_INCLUDED
#define MEM_FUN_HANDLER_HH_INCLUDED

namespace csr
{
////////////////////////////////////////////////////////////////////////////////
// class template mem_fun_handler
// Wraps pointers to member functions
////////////////////////////////////////////////////////////////////////////////

    template<class ParentFunctor,typename Ptr2Obj,typename Ptr2MemFn>
    class mem_fun_handler
    :   public ParentFunctor::impl
    {
        typedef typename ParentFunctor::impl base;

    public:
        typedef typename base::result_type  result_type;
        typedef typename base::parm01       parm01;
        typedef typename base::parm02       parm02;
        typedef typename base::parm03       parm03;
        typedef typename base::parm04       parm04;
        typedef typename base::parm05       parm05;
        typedef typename base::parm06       parm06;
        typedef typename base::parm07       parm07;
        typedef typename base::parm08       parm08;
        typedef typename base::parm09       parm09;
        typedef typename base::parm10       parm10;
        typedef typename base::parm11       parm11;
        typedef typename base::parm12       parm12;
        typedef typename base::parm13       parm13;
        typedef typename base::parm14       parm14;
        typedef typename base::parm15       parm15;
        typedef typename base::parm16       parm16;
        typedef typename base::parm17       parm17;
        typedef typename base::parm18       parm18;
        typedef typename base::parm19       parm19;
        typedef typename base::parm20       parm20;
        typedef typename base::parm21       parm21;
        typedef typename base::parm22       parm22;
        typedef typename base::parm23       parm23;
        typedef typename base::parm24       parm24;
        typedef typename base::parm25       parm25;
        typedef typename base::parm26       parm26;
        typedef typename base::parm27       parm27;
        typedef typename base::parm28       parm28;
        typedef typename base::parm29       parm29;
        typedef typename base::parm30       parm30;
        typedef typename base::parm31       parm31;
        typedef typename base::parm32       parm32;
        typedef typename base::parm33       parm33;
        typedef typename base::parm34       parm34;
        typedef typename base::parm35       parm35;
        typedef typename base::parm36       parm36;
        typedef typename base::parm37       parm37;
        typedef typename base::parm38       parm38;
        typedef typename base::parm39       parm39;
        typedef typename base::parm40       parm40;
        typedef typename base::parm41       parm41;
        typedef typename base::parm42       parm42;
        typedef typename base::parm43       parm43;
        typedef typename base::parm44       parm44;
        typedef typename base::parm45       parm45;
        typedef typename base::parm46       parm46;
        typedef typename base::parm47       parm47;
        typedef typename base::parm48       parm48;
        typedef typename base::parm49       parm49;
        typedef typename base::parm50       parm50;

        mem_fun_handler(const Ptr2Obj& pobj,Ptr2MemFn pmemfn)
        :   pobj_(pobj),pmemfn_(pmemfn) { ; }

        virtual mem_fun_handler* do_clone() const
        { return new mem_fun_handler(*this); }

        result_type operator()()
        { return ((*this->pobj_).*this->pmemfn_)(); }

        result_type operator()(parm01 p01)
        { return ((*this->pobj_).*this->pmemfn_)(p01); }

        result_type operator()(parm01 p01,parm02 p02)
        { return ((*this->pobj_).*this->pmemfn_)(p01,p02); }

        result_type operator()(parm01 p01,parm02 p02,parm03 p03)
        { return ((*this->pobj_).*this->pmemfn_)(p01,p02,p03); }

        result_type operator()(parm01 p01,parm02 p02,parm03 p03,parm04 p04)
        { return ((*this->pobj_).*this->pmemfn_)(p01,p02,p03,p04); }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05
                    )
        { return ((*this->pobj_).*this->pmemfn_)(p01,p02,p03,p04,p05); }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06
                    )
        { return ((*this->pobj_).*this->pmemfn_)(p01,p02,p03,p04,p05,p06); }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08,p09
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08,p09,p10
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                        p11
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                        p11,p12
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                        p11,p12,p13
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                        p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                        p11,p12,p13,p14
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44,parm45 p45
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44,p45
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44,parm45 p45,
                        parm46 p46
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44,p45,p46
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44,parm45 p45,
                        parm46 p46,parm47 p47
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44,p45,p46,p47
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44,parm45 p45,
                        parm46 p46,parm47 p47,parm48 p48
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44,p45,p46,p47,p48
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44,parm45 p45,
                        parm46 p46,parm47 p47,parm48 p48,parm49 p49
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44,p45,p46,p47,p48,p49
                    );
        }

        result_type operator()
                    (
                        parm01 p01,parm02 p02,parm03 p03,parm04 p04,parm05 p05,
                        parm06 p06,parm07 p07,parm08 p08,parm09 p09,parm10 p10,
                        parm11 p11,parm12 p12,parm13 p13,parm14 p14,parm15 p15,
                        parm16 p16,parm17 p17,parm18 p18,parm19 p19,parm20 p20,
                        parm21 p21,parm22 p22,parm23 p23,parm24 p24,parm25 p25,
                        parm26 p26,parm27 p27,parm28 p28,parm29 p29,parm30 p30,
                        parm31 p31,parm32 p32,parm33 p33,parm34 p34,parm35 p35,
                        parm36 p36,parm37 p37,parm38 p38,parm39 p39,parm40 p40,
                        parm41 p41,parm42 p42,parm43 p43,parm44 p44,parm45 p45,
                        parm46 p46,parm47 p47,parm48 p48,parm49 p49,parm50 p50
                    )
        {
            return ((*this->pobj_).*this->pmemfn_)
                    (
                            p01,p02,p03,p04,p05,p06,p07,p08,p09,p10,
                            p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,
                            p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,
                            p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,
                            p41,p42,p43,p44,p45,p46,p47,p48,p49,p50
                    );
        }

    private:
        Ptr2Obj pobj_;
        Ptr2MemFn pmemfn_;
    };
}

#endif // MEM_FUN_HANDLER_HH_INCLUDED
