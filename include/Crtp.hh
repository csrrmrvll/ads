#ifndef CRTP_H_INCLUDED
#define CRTP_H_INCLUDED

namespace csr
{
    template<typename Derived> class base
    {
        typedef typename Derived::argument_type argument_type;
        typedef typename Derived::output_type   output_type;

        argument_type _val;

    public:
        base(argument_type a)
            :   _val(a) {}

        output_type operator() (argument_type a) const
            { return Derived::operator()(a); }
    };

    template<typename Argument,typename Output> class derived
    :   public base<derived<Argument,Output> >
    {
        typedef base<derived<Argument,Output> > _base;

    public:
        typedef Argument        argument_type;
        typedef Output          output_type;

        derived(argument_type a)
        :   _base(a) {}

        output_type operator()(argument_type a) const { return 0; }
    };
}

#endif // CRTP_H_INCLUDED
