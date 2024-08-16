#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include "Span.hpp"

Span::Span():_size(0),_capacity(0){};

Span::Span(unsigned int c):_size(0),_capacity(c){
    //_vec = std::vector<int>(_capacity);
}

void Span::addNumber(const int number){
    if (_size == _capacity)
        throw std::exception();
    _vec.push_back(number);
    _size++;
}

/*
void Span::addNumber(iter_vec  begin, iter_vec end){
    //iter_vec it = begin;
    //std::vector<int> vec(20);
    for (iter_vec it = begin; it != end;++it){
        addNumber(*it);
    }
}
*/

/*
template <typename T>
    void addNumber(typename T::const_iterator begin, typename T::const_iterator end){
    //iter_vec it = begin;
    //std::vector<int> vec(20);
    //it = vec.begin();
    for (auto& it = begin; it != end;++it){
        addNumber(*it);
    }
}

template <typename T>
    void addNumber(typename T::iterator begin, typename T::iterator end){
    //iter_vec it = begin;
    //std::vector<int> vec(20);
    //it = vec.begin();
    for (auto& it = begin; it != end;++it){
        addNumber(*it);
    }
}
*/

unsigned int Span::shortestSpan() const {
    if (_size < 2)
        throw std::exception();
    // for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end();++it){
    //     std::cout << "current=" << *it << "\n";
    // }
    unsigned int min = _diff(_vec[0],_vec[1]);
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    unsigned int previous = _vec[0];
    unsigned int current = previous;
    unsigned int diff;
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end();++it){
        current = *it;
    //    std::cout << "current=" << current << "\n";
        diff = _diff(previous, current);
        if (min > diff)
            min = diff;
        previous = current;
    }
    return min;
}

unsigned int Span::longestSpan() const {
    if (_size < 2)
        throw std::exception();
    auto minMaxPair = std::minmax_element(_vec.begin(), _vec.end());
  //  std::cout << "max=" << *(minMaxPair.second) << "  min=" << *(minMaxPair.first);
    return _diff(*minMaxPair.second, *minMaxPair.first);
}

unsigned int Span::_diff(int a, int b){
    return static_cast<unsigned int>(a > b ? a - b : b - a);
}

void Span::print() const{
    for (auto& r: _vec){
        std::cout << r << " ";
    }
    std::cout << "\n";
}