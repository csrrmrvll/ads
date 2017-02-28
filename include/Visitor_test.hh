#ifndef VISITOR_TEST_HH_INCLUDED
#define VISITOR_TEST_HH_INCLUDED

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "Visitor.hh"

using namespace std;

void testVisitor();
void testCyclicVisitor();

struct docElement
:   public csr::visitable<>
{
    MAKE_VISITABLE()
};

struct paragraph
:   public docElement
{
    MAKE_VISITABLE()
};

typedef std::vector<paragraph> par_vector;

class multipleParagraph
:   public csr::visitable<>
{
public:
    multipleParagraph(const par_vector& src)
    :   pars_(src) { ; }

    void add(const paragraph& src)
    {
        this->pars_.push_back(src);
    }

    void accept(csr::base_visitor& v)
    {
        cout << "Visiting multipleParagraph!!!" << endl;
        par_vector::iterator    first = this->pars_.begin(),
                                last = this->pars_.end();
        for (   ; first != last; ++first)
        {
            first->accept(v);
        }
    }

private:
    par_vector pars_;
};

// Fwd decls., needed by cyclic_visitor
class docElement2;
class paragraph2;

typedef csr::typelist<docElement2,paragraph2> visitable2_types;

typedef csr::cyclic_visitor<visitable2_types,void> myVisitor3;

struct docElement2
:   public csr::cyclic_visitable<>
{
    MAKE_CYCLIC_VISITABLE(myVisitor3)
};

struct paragraph2
:   public docElement2
{
    MAKE_CYCLIC_VISITABLE(myVisitor3)
};

typedef std::vector<paragraph2> par2_vector;

class multipleParagraph2
:   public csr::cyclic_visitable<>
{
public:
    multipleParagraph2(const par2_vector& src)
    :   pars_(src) { ; }

    void add(const paragraph2& src)
    {
        this->pars_.push_back(src);
    }

    void accept(myVisitor3& v)
    {
        cout << "Visiting multipleParagraph2!!!" << endl;
        par2_vector::iterator   first = this->pars_.begin(),
                                last = this->pars_.end();
        for (   ; first != last; ++first)
        {
            first->accept(v);
        }
    }

private:
    par2_vector pars_;
};

#endif // VISITOR_TEST_HH_INCLUDED
