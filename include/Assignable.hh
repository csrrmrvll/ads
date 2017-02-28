#ifndef ASSIGNABLE_HH_INCLUDED
#define ASSIGNABLE_HH_INCLUDED

namespace csr
{
    template<typename T>
    struct assignable
    {
        const T& operator=(T& other)
        {
            T tmp(other);
            static_cast<T*>(this)->swap(tmp);
            return *this;
        }
    };

    class test_assignable
    :   public assignable<test_assignable>
    {
    public:
        test_assignable(const int i)
        :   i_(i)
        { ; }

    private:
        int i_;

        void swap(test_assignable& other)
        {
            std::swap(this->i_,other.i_);
        }
    };
}

#endif // ASSIGNABLE_HH_INCLUDED
