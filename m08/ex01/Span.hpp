#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

using u_int = unsigned int;
using vec_u = std::vector<u_int>;

class Span{
public:
    Span(size_t);
    Span();
    ~Span() = default;
    void addNumber(u_int);
    u_int shortesSpan();
    u_int longestSpan();
private:
    vec_u _vec;
    size_t _size;
    const size_t _capacity;
    u_int _diff(u_int, u_int);
};

#endif