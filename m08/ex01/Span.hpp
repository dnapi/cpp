#ifndef SPAN_HPP
#define SPAN_HPP

using u_int = unsigned int;

class Span{
    public:
    u_int *arr;
    Span(u_int);
    Span();
    ~Span();
    void addNumber(u_int);
    u_int shortesSpan();
    u_int longestSpan()};

#endif