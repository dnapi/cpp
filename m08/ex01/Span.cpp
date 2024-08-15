#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Span.hpp"

Span::Span():_size(0),_capacity(0){};

Span::Span(unsigned int c):_size(0),_capacity(c){
    //_vec = std::vector<int>(_capacity);
}

void Span::addNumber(unsigned int number){
    if (_size == _capacity)
        throw std::exception();
    _vec.push_back(number);
    _size++;
}

unsigned int Span::shortestSpan(){
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

unsigned int Span::longestSpan(){
    if (_size < 2)
        throw std::exception();
    auto minMaxPair = std::minmax_element(_vec.begin(), _vec.end());
    std::cout << "max=" << *(minMaxPair.second) << "  min=" << *(minMaxPair.first);
    return _diff(*minMaxPair.second, *minMaxPair.first);
}

unsigned int Span::_diff(unsigned int a, unsigned int b){
    return a > b ? a - b : b - a;
}