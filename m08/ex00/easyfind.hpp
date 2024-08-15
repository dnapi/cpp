
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <array>
#include <deque>
#include <list>
#include <vector>

//template <template<int> typename Container = std::vector>
template <typename T>
typename T::const_iterator easyfind(T t, int i){
    T::const_iterator it = std::find(t.begin(), t.end(), i); 
    if (it == t.end())
        throw std::exception();
    return it;
}

template <typename T>
typename T::iterator easyfind(T t, int i){
    T::iterator it = std::find(t.begin(), t.end(), i); 
    if (it == t.end())
        throw std::exception();
    return it;
}

#endfi