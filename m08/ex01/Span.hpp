#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

using iter_vec = std::vector<int>::const_iterator;

class Span{
public:
    Span(unsigned int);
    Span();
    ~Span() = default;
    void addNumber(int);
    void addNumber(iter_vec, iter_vec);
    unsigned int shortestSpan();
    unsigned int longestSpan();
private:
    std::vector<int> _vec;
    size_t _size;
    const unsigned int _capacity;
    unsigned int _diff(int, int);
};

#endif