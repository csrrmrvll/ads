#ifndef FACTORY_TEST_HH_INCLUDED
#define FACTORY_TEST_HH_INCLUDED

#include "Null.hh"

using namespace csr;
using namespace std;

struct A
{
    A(const int a) { cout << "A" << a << endl; }
    virtual ~A() { ; }
};
struct B
:   virtual public A
{
    B(const int a)
    :   A(a) { cout << "B" << a << endl; }
};
struct C
:   virtual public A
{
    C(const int a)
    :   A(a) { cout << "C" << a << endl; }
};
struct D
:   public B,
    public C
{
    D(const int a)
    :   A(a),B(a),C(a) { cout << "D" << a << endl; }
};

A* createA(const int a) { return new A(a); }

B* createB(const int a) { return new B(a); }

C* createC(const int a) { return new C(a); }

D* createD(const int a) { return new D(a); }

template
<
    typename U,
    typename T01 = void_t,typename T02 = void_t,
    typename T03 = void_t,typename T04 = void_t
>
struct create
{
    U* operator()() { return new U(); }
    U* operator()(T01 t01) { return new U(t01); }
    U* operator()(T01 t01,T02 t02) { return new U(t01,t02); }
    U* operator()(T01 t01,T02 t02,T03 t03) { return new U(t01,t02,t03); }
    U* operator()(T01 t01,T02 t02,T03 t03,T04 t04) { return new U(t01,t02,t03,t04); }
};

#endif // FACTORY_TEST_HH_INCLUDED
