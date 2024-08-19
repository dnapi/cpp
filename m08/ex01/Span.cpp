/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:00:56 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/19 13:43:21 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include "Span.hpp"

Span::Span():_size(0),_capacity(0){};

Span::Span(unsigned int c):_size(0),_capacity(c){}

void Span::addNumber(const int number){
    if (_size == _capacity)
        throw std::exception();
    _vec.push_back(number);
    _size++;
}

unsigned int Span::shortestSpan() const {
    if (_size < 2)
        throw std::exception();
    unsigned int min = _diff(_vec[0],_vec[1]);
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    unsigned int previous = tmp[0];
    unsigned int current = previous;
    unsigned int diff;
    for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end();++it){
        current = *it;
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