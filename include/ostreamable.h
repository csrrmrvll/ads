#ifndef OUTSTREAMABLE_HH_INCLUDED
#define OUTSTREAMABLE_HH_INCLUDED

#include <iosfwd>

namespace ads
{
    template<typename T>
    struct Ostreamable
    {
        std::ostream & print(std::ostream & os) const
        {
            return static_cast<const T*>(this)->print(os);
        }

        friend std::ostream & operator<<(std::ostream & out,const Ostreamable & os)
        {
            os.print(out);
            return out;
        }
    };
}

#endif // OUTSTREAMABLE_HH_INCLUDED
