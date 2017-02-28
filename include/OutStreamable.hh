#ifndef OUTSTREAMABLE_HH_INCLUDED
#define OUTSTREAMABLE_HH_INCLUDED

#include <iosfwd>

namespace csr
{
    template<typename T>
    struct OutStreamable
    {
        std::ostream & print(std::ostream & os) const
        {
            return static_cast<const T*>(this)->print(os);
        }

        friend std::ostream & operator<<(std::ostream & out,const OutStreamable & os)
        {
            os.print(out);
            return out;
        }
    };

    struct TestOutStreamable
    :   public OutStreamable<TestOutStreamable>
    {
        std::ostream& print(std::ostream& out) const
        {
            out << "\tprinting test_out_streamable" << std::endl;
            return out;
        }
    };
}

#endif // OUTSTREAMABLE_HH_INCLUDED
