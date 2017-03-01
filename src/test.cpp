#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <tuple>
#include "ads.h"

using namespace std;
using namespace ads;

void test_func(int a) { cout << "A: " << a << endl; }

struct test_ostreamable
:   public ostreamable<test_ostreamable>
{
    ostream & print(ostream & out) const
    {
        out << endl << "printing test_out_streamable" << endl;
        return out;
    }
};

int main()
{
    tuple<int,int,int> tup(1,1,1);
    get<1>(tup);
    test_ostreamable tos;
    cout << tos;

    array<int,5> ar = { 1,2,3,4,5 };
    array<int,5> br = { 2,4,6,8,10 };
    int dummy[5];
    fill_n(dummy,5,0);
    if (find(ar,10).second == false)
    {
        cout << "Not found!: a" << endl;
    }
    auto fun = [](int a){ return a < 10; };
    auto p = findIf(br,fun);
    if (p.second)
    {
        cout << "Found!: " << *p.first << endl;
    }
    if (copy_if(ar.begin(),ar.end(),br.begin(),fun) == br.end())
    {
        cout << "Copied!: a in b" << endl;
    }
    vector<pair<int,int>> pairs(5);
    for (int m = 0; m < 5; ++m)
    {
        pairs[m] = make_pair(m, ar[m]);
    }
    sorted_vector<int,int> iavec;
    iavec.insert(pairs.begin(),pairs.end());
    pair<int,int> ten(4,10);
    if (find(iavec,ten).second == false)
    {
        cout << "Not found!: a" << endl;
    }
    auto fun2 = [&](const pair<int,int> & p){ return p < ten; };
    if (findIf(iavec,fun2).second)
    {
        cout << "Found!: b" << endl;
    }
    map<int,int> imap(pairs.begin(),pairs.end());
    if (find(imap,ten).second == false)
    {
        cout << "Not found!: a" << endl;
    }
    if (findIf(imap,fun2).second)
    {
        cout << "Found!: b" << endl;
    }
    set<int> iset(ar.begin(),ar.end());
    if (find(iset,10).second == false)
    {
        cout << "Not found!: a" << endl;
    }
    if (findIf(iset,fun).second)
    {
        cout << "Found!: b" << endl;
    }
    copy(br.begin(),br.end(),ostream_iterator<double>(cout, " "));
    cout << endl << "Presiona intro para salir" << endl;
    cin.get();
    return 0;
}
