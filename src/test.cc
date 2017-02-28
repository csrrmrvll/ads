#include <iostream>
#include <iterator>
#include <set>
#include <tuple>
#include <functional>
#include <array>

#include "Csr.hh"
#include "factory_test.hh"
#include "visitor_test.hh"

using namespace std;
using namespace csr;

void test_func(int a) { cout << "A: " << a << endl; }

int main()
{
    std::tuple<int,int,int> tup(1,1,1);
    std::get<1>(tup);
    test_assignable ta(1),
                    tb(2);
    ta = tb;
    TestOutStreamable tos;
    cout << tos;

    testVisitor();
    testCyclicVisitor();

//    typedef select<same_type<int,short>::value,int,short>::result ret;
//    factory<A,std::string,typelist<const int> > fac;
//    A a(1);
//    B b(1);
//    C c(1);
//    D d(1);

//    functor<A*,typelist<const int> > fa(createA);
//    fac.record("A",createA);
//    fac.record("A",fa);
//
//    create<B,int,int> bcreator;
//    fac.record("B",bcreator);
//
//    create<C,int> ccreator;
//    fac.record("C",ccreator);
//
//    create<D,int> dcreator;
//    fac.record("D",dcreator);
//
//    std::auto_ptr<A> pa(fac.create("A",1));
//    std::auto_ptr<B> pb(fac.create<B,int,int>("B",1,1));

//    functor<void,typelist<int> > ftor(test_func);
//    ftor(35);

    array<int,5> ar = {{ 1,2,3,4,5 }};
    array<int,5> br = {{ 2,4,6,8,10 }};
    int dummy[5];
    fill_n(dummy,5,0);
    if (find_pos(ar,10).second == false)
        cout << "Not found!: a" << endl;

    if (find_pos_if(br,less_than<int>(10)).second)
        cout << "Found!: b" << endl;

    if (copy_if(ar.begin(),ar.end(),br.begin(),less_than<int>(10)) == br.end())
        cout << "Copied!: a in b" << endl;

    std::vector<std::pair<int,int> > pairs(5);
    for (int m = 0; m < 5; ++m)
    {
        pairs[m] = std::make_pair(m, ar[m]);
    }
    assoc_vector<int,int> iavec;
    iavec.insert(pairs.begin(),pairs.end());
    std::pair<int,int> ten(4,10);
    if (find_pos(iavec,ten).second == false)
        cout << "Not found!: a" << endl;

    if (find_pos_if(iavec,less_than<std::pair<int,int> >(ten)).second)
        cout << "Found!: b" << endl;

    std::map<int,int> imap(pairs.begin(),pairs.end());
    if (find_pos(imap,ten).second == false)
        cout << "Not found!: a" << endl;

    if (find_pos_if(imap,less_than<std::pair<int,int> >(ten)).second)
        cout << "Found!: b" << endl;

    std::set<int> iset(ar.begin(),ar.end());
    if (find_pos(iset,10).second == false)
        cout << "Not found!: a" << endl;

    if (find_pos_if(iset,less_than<int>(10)).second)
        cout << "Found!: b" << endl;

    copy(br.begin(),br.end(),ostream_iterator<double>(cout, " "));
    cout << endl << "Presiona intro para salir" << endl;
    cin.get();
    return 0;
}
