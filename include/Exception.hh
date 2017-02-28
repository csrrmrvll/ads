#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <exception>
#include <string>

using std::string;

namespace csr
{
    class out_of_range
    :   public std::exception
    {
    public:
        typedef std::exception base;

        out_of_range(string str) throw()
        :   base(),_where(str) { this->_where += ": out of range"; }

        const char* what() throw() { return this->_where.c_str(); }

        ~out_of_range() throw() { ; }

    private:
        string _where;
    };
}

#endif // EXCEPTION_H_INCLUDED
