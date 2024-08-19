#include <iostream>
#include <list>
#include <random>
#include "Span.hpp"

std::vector<int> generateRandomIntVector(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);

    std::vector<int> randomInts;
    for (int i = 0; i < size; ++i) {
        randomInts.push_back(distr(eng));
    }

    return randomInts;
}

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

    std::cout << "\nRange of iterators\n";
    Span sp2 = Span(100);
    
    std::vector<int> vec = {1,3,5,7};
    sp2.addList(vec.begin(),vec.end());
    sp2.print();
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    
    std::list<int> l = {8, 9, -9};
    sp2.addList(l.begin(), l.end());
    sp2.print();
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    std::list<long> ll = {20,43};
    sp2.addList(ll.begin(), ll.end());
    sp2.print();
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    Span span_big = Span(2'000'000);

    std::vector<int> vect = generateRandomIntVector(2'000'000, std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
    span_big.addList(vect.begin(), vect.end());
    //span_big.print();
    std::cout << span_big.shortestSpan() << std::endl;
    std::cout << span_big.longestSpan() << std::endl;
    return 0;
}


