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

template<typename T>
ostream & operator<<(ostream & os, const range<T> & r)
{
    copy(begin(r),end(r),ostream_iterator<typename range<T>::value_type>(os, " "));
    return os;
}

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
    if (find(ar,10).found == false)
    {
        cout << "10 not found! in a" << endl;
    }
    auto fun = [](int a){ return a < 10; };
    auto p = find_if(br,fun);
    if (p.found)
    {
        cout << "Found!: " << *p.pos << endl;
    }
    if (copy_if(begin(ar),ar.end(),br.begin(),fun) == br.end())
    {
        cout << "Copied a in b:"
        << endl << make_range(ar)
        << endl << make_range(br) << endl;
    }
    using pair = pair<int,int>;
    vector<pair> pairs(5);
    for (auto m : make_numerical_range(0,4))
    {
        pairs[m] = {m + 1, ar[m]};
    }
    using ordered_pairs = increase_sequence<pair>;
    ordered_pairs opairs;
    opairs.push(make_range(pairs));
    pair ten(4,10);
    if (find(opairs,ten).found == false)
    {
        cout << "Not found!: a" << endl;
    }
    auto fun2 = [&](const pair & p){ return p < ten; };
    if (find_if(opairs,fun2).found)
    {
        cout << "Found!: b" << endl;
    }
    map<int,int> imap(pairs.begin(),pairs.end());
    if (find(imap,ten).found == false)
    {
        cout << "Not found!: a" << endl;
    }
    if (find_if(imap,fun2).found)
    {
        cout << "Found!: b" << endl;
    }
    set<int> iset(begin(br),end(br));
    if (find(iset,10).found == false)
    {
        cout << "Not found!: a" << endl;
    }
    if (find_if(iset,fun).found)
    {
        cout << "Found!: b" << endl;
    }
    copy(br,ostream_iterator<double>(cout, " "));
    min_heap<int> h;
    range<ordered_pairs::iterator> r(begin(opairs),end(opairs));
    range<array<int,5>::iterator> r2(begin(br),end(br));
    return 0;
}
