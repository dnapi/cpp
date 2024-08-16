#include <iostream>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(11);
    }
    catch (...){
        std::cout << " exception: Span is full\n";
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(100);
    std::vector<int> vec = {1,2,3,4,5,6};
    sp2.addNumber(vec.begin(),vec.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    sp2.print();
    return 0;
}


