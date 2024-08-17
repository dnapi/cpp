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
    //void addNumber(iter_vec, iter_vec);
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