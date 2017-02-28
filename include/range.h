#ifndef RANGE_H
#define RANGE_H

namespace ads
{
    template<typename Iterator>
    class Range
    {
    public:
        using iterator = Iterator;
        iterator begin() const { return this->begin_; }
        iterator end() const { return this->end_; }

    private:
        iterator    begin_,
                    end_;
    };
}

#endif // RANGE_H
