#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span{
public:
    Span(unsigned int);
    Span();
    ~Span() = default;
    void addNumber(u_int);
    unsigned int shortestSpan();
    unsigned int longestSpan();
private:
    std::vector<int> _vec;
    size_t _size;
    const unsigned int _capacity;
    unsigned int _diff(u_int, u_int);
};

#endif