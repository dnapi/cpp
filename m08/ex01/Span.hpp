/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:01:11 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/19 13:01:13 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

using iter_vec = std::vector<int>::const_iterator;

class Span{
public:
    Span(unsigned int);
    Span();
    ~Span() = default;
    void addNumber(const int);
    template <typename T>
    void addList(T begin, T end){
        for (auto it = begin; it != end;++it){
            addNumber(*it);
        }
    }
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    void print() const;
private:
    std::vector<int> _vec;
    size_t _size;
    const unsigned int _capacity;
    static unsigned int _diff(int, int);
};

#endif