#ifndef ADS_NUMERICAL_RANGE_H
#define ADS_NUMERICAL_RANGE_H

#include <utility>

namespace ads
{
    template<typename Integral>
    class numerical_range_iterator
    {
    public:
        explicit numerical_range_iterator(Integral & i)
        :   element(i)
        {
        }

        using value_type = Integral;
        value_type operator*() const
        {
            return this->element;
        }

        numerical_range_iterator & operator++()
        {
            ++this->element;
            return *this;
        }

        numerical_range_iterator operator++(int)
        {
            return this->element++;
        }

    private:
        Integral & element;
    };

    template<typename Integral>
    bool operator==(const numerical_range_iterator<Integral> & lhs,
                    const numerical_range_iterator<Integral> & rhs)
    {
        return *lhs == *rhs;
    }

    template<typename Integral>
    bool operator!=(const numerical_range_iterator<Integral> & lhs,
                    const numerical_range_iterator<Integral> & rhs)
    {
        return *lhs != *rhs;
    }

    template<typename Integral>
    bool operator<(const numerical_range_iterator<Integral> & lhs,
                    const numerical_range_iterator<Integral> & rhs)
    {
        return *lhs < *rhs;
    }

    template<typename Integral>
    bool operator<=(const numerical_range_iterator<Integral> & lhs,
                    const numerical_range_iterator<Integral> & rhs)
    {
        return *lhs <= *rhs;
    }

    template<typename Integral>
    bool operator>(const numerical_range_iterator<Integral> & lhs,
                    const numerical_range_iterator<Integral> & rhs)
    {
        return *lhs > *rhs;
    }

    template<typename Integral>
    bool operator>=(const numerical_range_iterator<Integral> & lhs,
                    const numerical_range_iterator<Integral> & rhs)
    {
        return *lhs >= *rhs;
    }

    template<typename Integral>
    class numerical_range
    :   private std::pair<Integral,Integral>
    {
        using base = std::pair<Integral,Integral>;
    public:
        numerical_range(Integral first, Integral last)
        :   base(first,last)
        {
        }

        using iterator = numerical_range_iterator<Integral>;
        using value_type = typename iterator::value_type;

        iterator begin()
        {
            return iterator(this->first);
        }

        iterator end()
        {
            return iterator(this->second);
        }
    };

    template<typename Integral>
    numerical_range<Integral> make_numerical_range(Integral first, Integral last)
    {
        return numerical_range<Integral>(first, last);
    }
}

#endif // ADS_NUMERICAL_RANGE_H
