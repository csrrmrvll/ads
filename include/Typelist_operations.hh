#ifndef TYPELIST_OPERATIONS_HH_INCLUDED
#define TYPELIST_OPERATIONS_HH_INCLUDED

#include <climits>

namespace csr
{
    template<typename TList> struct length
    {
        enum { value = length<typename TList::tail>::value };
    };

    template<> struct length<void_t>
    {
        enum { value = 0 };
    };

    // not defined for void_t to get a compilation error
    // when accessing out of bounds.
    template<typename TList = void_t,size_t index = UINT_MAX> struct type_at;

    template<typename Head,typename Tail>
    struct type_at<typelist<Head,Tail>,0>
    {
        typedef Head result;
    };
    // recursive
    template<typename Head,typename Tail,size_t N>
    struct type_at<typelist<Head,Tail>,N>
    {
        typedef typename type_at<Tail,N - 1>::result result;
    };

    template<typename TList,typename T> class index_of
    {
        typedef typename TList::tail tail;
        enum { tmp = index_of<tail,T>::value };

    public:
        enum { value = (tmp == -1) ? -1 : (1 + tmp) };
    };

    template<typename T> struct index_of<void_t,T>
    {
        enum { value = -1 };
    };

    template<typename T,typename Tail>
    struct index_of<typelist<T,Tail>,T>
    {
        enum { value = 0 };
    };

    template<typename TList,typename T> struct append;

    template<> struct append<void_t,void_t>
    {
        typedef void_t result;
    };

    template<typename T> struct append<void_t,T>
    {
        typedef typelist<T,void_t> result;
    };

    template<typename Head,typename Tail>
    struct append<void_t,typelist<Head,Tail> >
    {
        typedef typelist<Head,Tail> result;
    };

    template<typename Head,typename Tail,typename T>
    struct append<typelist<Head,Tail>,T>
    {
        typedef typelist<Head,typename append<Tail,T>::result> result;
    };

    template<typename TList,typename T> struct erase;

    template<typename T> struct erase<void_t,T>
    {
        typedef void_t result;
    };

    template<typename T,typename Tail> struct erase<typelist<T, Tail>,T>
    {
        typedef Tail result;
    };

    template<typename Head,typename Tail,typename T>
    struct erase<typelist<Head,Tail>,T>
    {
        typedef typelist<Head,typename erase<Tail,T>::result> result;
    };

    template<typename TList,typename T> struct erase_all;

    template<typename T> struct erase_all<void_t,T>
    {
        typedef void_t result;
    };

    template<typename T,typename Tail> struct erase_all<typelist<T,Tail>,T>
    {
        // Go all the way down the list removing the type
        typedef typename erase_all<Tail,T>::result result;
    };

    template<typename Head,typename Tail,typename T>
    struct erase_all<typelist<Head,Tail>,T>
    {
        // Go all the way down the list removing the type
        typedef typelist<Head,typename erase_all<Tail,T>::result> result;
    };

    template<typename TList> struct no_duplicates;

    template<> struct no_duplicates<void_t>
    {
        typedef void_t result;
    };

    template<typename Head,typename Tail>
    class no_duplicates<typelist<Head,Tail> >
    {
        typedef typename no_duplicates<Tail>::result    List1;
        typedef typename erase<List1,Head>::result      List2;

    public:
        typedef typelist<Head,List2> result;
    };

    template<typename TList,typename T,typename U> struct replace;

    template<typename T,typename U>
    struct replace<void_t,T,U>
    {
        typedef void_t result;
    };

    template<typename T,typename Tail,typename U>
    struct replace<typelist<T,Tail>,T,U>
    {
        typedef typelist<U,Tail> result;
    };

    template<typename Head,typename Tail,typename T,typename U>
    struct replace<typelist<Head,Tail>,T,U>
    {
        typedef typelist<Head,typename replace<Tail, T, U>::result> result;
    };

    template<typename TList,typename T,typename U> struct replace_all;

    template<typename T,typename U> struct replace_all<void_t,T,U>
    {
        typedef void_t result;
    };

    template<typename T,typename Tail,typename U>
    struct replace_all<typelist<T,Tail>,T,U>
    {
        typedef typelist<U,typename replace_all<Tail, T, U>::result> result;
    };

    template<typename Head,typename Tail,typename T,typename U>
    struct replace_all<typelist<Head,Tail>,T,U>
    {
        typedef typelist<Head,typename replace_all<Tail, T, U>::result> result;
    };

    template<class TList> struct reverse;

    template<> struct reverse<void_t>
    {
        typedef void_t result;
    };

    template<class Head,class Tail>
    class reverse<typelist<Head,Tail> >
    {
        typedef typename reverse<Tail>::result reversed_tail_list;

    public:
        typedef typename append<reversed_tail_list,Head>::result result;
    };

    template<typename TList,typename T>
    class most_derived
    {
        typedef typename TList::tail                     tail_list;
        typedef typename TList::head                     head_type;
        typedef typename most_derived<tail_list,T>::result  candidate;
        enum { value = super_sub_type<candidate,head_type>::value };

    public:
        typedef typename select<value,head_type,candidate>::result result;
    };

    template<typename T> struct most_derived<void_t,T>
    {
        typedef T result;
    };

    template<typename TList>
    class derived2front
    {
        typedef typename TList::tail               tail_list;
        typedef typename TList::head               head_type;
        typedef typename most_derived
                            <
                                tail_list,
                                head_type
                            >::result                   most_derived;
        typedef typename replace
                            <
                                tail_list,
                                most_derived,
                                head_type
                            >::result                   tmp;
        typedef typename derived2front<tmp>::result    tail_result;

    public:
        typedef typelist<most_derived,tail_result> result;
    };


    template<>
    struct derived2front<void_t>
    {
        typedef void_t result;
    };
}

#endif // TYPELIST_OPERATIONS_HH_INCLUDED
