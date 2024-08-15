#include <vector>
#include <algorithm>
#include <limits>
#include "Span.hpp"

Span::Span():_size(0),_capacity(0){};

Span::Span(size_t c):_size(0),_capacity(c){
    _vec = std::vector<u_int>(_capacity);
}

void Span::addNumber(u_int number){
    if (_size == _capacity)
        throw std::exception();
    _vec.push_back(number);
    _size++;
}

u_int Span::shortesSpan(){
    if (_size < 2)
        throw std::exception();
    u_int min = _diff(_vec[0],_vec[1]);
    vec_u tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    u_int previous = vec[0];
    for (std::vector<u_int>::iterator it = tmp.begin() + 1; it != tmp.end();++it){
        u_int current = *it;
        u_int diff = _diff(previous, current);
        if (min > diff)
            min = diff;
        u_int previous = current;
    }
    return min;
}

u_int Span::longestSpan(){
    if (_size < 2)
        throw std::exception();
    auto minMaxPair = std::minmax_element(_vec.begin(), _vec.end());
    return static_cast<unsigned int>(*minMaxPair.second - *minMaxPair.first);
}

u_int Span::_diff(u_int a, u_int b){
    return a > b ? a - b : b - a;
}