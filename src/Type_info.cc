#include "Type_info.hh"

namespace csr
{
    typeinfo::typeinfo()
    :   pinfo_(0) { ; }

    typeinfo::typeinfo(const std::type_info& info)
    :   pinfo_(&info) { ; }

    typeinfo::typeinfo(const typeinfo& other)
    :   pinfo_(other.pinfo_) { ; }

    typeinfo& typeinfo::operator=(const typeinfo& other)
    {
        this->pinfo_ = other.pinfo_;
        return *this;
    }

    typeinfo::~typeinfo() { pinfo_ = 0; }

    bool typeinfo::before(const typeinfo& other) const
    { return this->pinfo_->before(*other.pinfo_); }

    const char* typeinfo::name() const
    { return this->pinfo_->name(); }

    bool operator==(const typeinfo& a,const typeinfo& b)
    { return *a.pinfo_ == *b.pinfo_; }

    bool operator!=(const typeinfo& a,const typeinfo& b)
    { return *a.pinfo_ != *b.pinfo_; }

    bool operator<(const typeinfo& a,const typeinfo& b)
    { return a.before(*b.pinfo_); }

    bool operator<=(const typeinfo& a,const typeinfo& b)
    { return a == b || a < b; }

    bool operator>(const typeinfo& a,const typeinfo& b)
    { return !(a <= b); }

    bool operator>=(const typeinfo& a,const typeinfo& b)
    { return !(a < b); }
}
