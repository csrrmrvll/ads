#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <tuple>

#include "Csr.hh"

using namespace std;
using namespace csr;

void test_func(int a) { cout << "A: " << a << endl; }

int main()
{
    std::tuple<int,int,int> tup(1,1,1);
    std::get<1>(tup);
    TestOutStreamable tos;
    cout << tos;

    array<int,5> ar = { 1,2,3,4,5 };
    array<int,5> br = { 2,4,6,8,10 };
    int dummy[5];
    fill_n(dummy,5,0);
    if (csr::find(ar,10).second == false)
        cout << "Not found!: a" << endl;

    auto fun = [](int a){ return a < 10; };
    if (find_if(br,fun).second)
        cout << "Found!: b" << endl;

    if (copy_if(ar.begin(),ar.end(),br.begin(),fun) == br.end())
        cout << "Copied!: a in b" << endl;

    std::vector<std::pair<int,int> > pairs(5);
    for (int m = 0; m < 5; ++m)
    {
        pairs[m] = std::make_pair(m, ar[m]);
    }
    assoc_vector<int,int> iavec;
    iavec.insert(pairs.begin(),pairs.end());
    std::pair<int,int> ten(4,10);
    if (find(iavec,ten).second == false)
        cout << "Not found!: a" << endl;

    auto fun2 = [&](const std::pair<int,int> & p){ return p < ten; };
    if (find_if(iavec,fun2).second)
        cout << "Found!: b" << endl;

    std::map<int,int> imap(pairs.begin(),pairs.end());
    if (find(imap,ten).second == false)
        cout << "Not found!: a" << endl;

    if (find_if(imap,fun2).second)
        cout << "Found!: b" << endl;

    std::set<int> iset(ar.begin(),ar.end());
    if (find(iset,10).second == false)
        cout << "Not found!: a" << endl;

    if (find_if(iset,fun).second)
        cout << "Found!: b" << endl;

    copy(br.begin(),br.end(),ostream_iterator<double>(cout, " "));
    cout << endl << "Presiona intro para salir" << endl;
    cin.get();
    return 0;
}
