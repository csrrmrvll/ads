#ifndef LIGHT_CONTAINER_HH_INCLUDED
#define LIGHT_CONTAINER_HH_INCLUDED

namespace csr
{
    template<typename Iterator>
    class range
    {
    public:
        typedef Iterator iterator;
        typedef typename std::iterator_traits<Iterator>::iterator_category  iterator_category;
        typedef typename std::iterator_traits<Iterator>::value_type         value_type;
        typedef typename std::iterator_traits<Iterator>::difference_type    difference_type;
        typedef typename std::iterator_traits<Iterator>::pointer            pointer;
        typedef typename std::iterator_traits<Iterator>::reference          reference;

        iterator begin() const { return this->begin_; }
        iterator end() const { return this->end_; }
        reference front() const { return *this->begin_; }
        reference back() const { return *(--this->end_); }

    private:
        iterator    begin_,
                    end_;
    };
}

#endif // LIGHT_CONTAINER_HH_INCLUDED
