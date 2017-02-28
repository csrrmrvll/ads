#ifndef MATH_HH_INCLUDED
#define MATH_HH_INCLUDED

namespace csr
{
    template<typename ArgType> class less_than
    {
    public:
        typedef ArgType argument_type;

        explicit less_than(argument_type arg)
        :   _val(arg) { ; }

        bool operator() (argument_type arg) const
        { return arg < this->_val; }

    private:
        argument_type   _val;
    };

    template<typename ArgType> class greater_than
    {
    public:
        typedef ArgType    argument_type;

        explicit greater_than(argument_type arg)
            :   _val(arg) {}

        bool operator() (argument_type arg) const
        { return arg > this->_val; }

    private:
        argument_type   _val;
    };
}

#endif // MATH_HH_INCLUDED
