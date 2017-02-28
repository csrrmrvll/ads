#ifndef ITERATOR_HH_INCLUDED
#define ITERATOR_HH_INCLUDED

/**
 *  Set of classes & functions as utilities for arrays with
 *  non stl-conforming interfaces.
 */
 namespace csr
 {
    template<typename T,size_t N> T* first (T(&ar)[N]) { return ar; }

    template<typename T,size_t N> T* last (T(&ar)[N]) { return ar + N; }

    template<typename T,size_t N> T* size(T(&)[N]) { return N; }
 }

#endif // ITERATOR_HH_INCLUDED
