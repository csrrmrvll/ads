#ifndef TYPE_INFO_HH_INCLUDED
#define TYPE_INFO_HH_INCLUDED

#include <typeinfo>

namespace csr
{
// wrapper for type_info objects. They're too clumsy and we provide value semantics
    class typeinfo
    {
    public:
        typeinfo(); // for containers
        typeinfo(const std::type_info&);
        typeinfo(const typeinfo&);
        typeinfo& operator=(const typeinfo&);
        ~typeinfo();
        bool before(const typeinfo&) const;
        const char* name() const;

        friend bool operator==(const typeinfo&,const typeinfo&);
        friend bool operator!=(const typeinfo&,const typeinfo&);
        friend bool operator<(const typeinfo&,const typeinfo&);
        friend bool operator<=(const typeinfo&,const typeinfo&);
        friend bool operator>(const typeinfo&,const typeinfo&);
        friend bool operator>=(const typeinfo&,const typeinfo&);

    private:
        const std::type_info* pinfo_;
    };
}

#endif // TYPE_INFO_HH_INCLUDED
