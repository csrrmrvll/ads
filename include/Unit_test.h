#ifndef UNIT_TEST_H_INCLUDED
#define UNIT_TEST_H_INCLUDED

namespace csr
{
    template<typename RetType,typename Class,typename Member> class unit_test
    {
    public:
        typedef RetType return_type;
        typedef Class   class_;
        typedef Member  f_;

        return_type operator()() { return class_::f_(); }
    };
} // !csr

#endif // UNIT_TEST_H_INCLUDED
