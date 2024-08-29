#pragma once

#include <iostream>
#include <vector>
#include <deque>

using vector_t = std::vector<unsigned int>;
//using vector_it = std::vector<unsigned int>::iterator;

class PmergeMe{
public:
//    std::vector<unsigned int> data_vec;
    vector_t a;
    vector_t b;
    size_t number_compare = 0;
    //std::deque<unsigned int> data_deq;
    //std::deque<unsigned int> data_deq;
    PmergeMe();
    vector_t sortVector(vector_t& v, size_t len);
    void makeTwoVectors(vector_t& vec);
    void makeMainChainVector();
    ~PmergeMe() = default;
private:
    bool less(unsigned int a, unsigned int b);
    void printVector(vector_t& v, size_t len = 10);
    void binaryInsertionVector(vector_t& v, vector_t& indexes, size_t mid_point);
    PmergeMe(const PmergeMe&) = default;
    PmergeMe& operator=(const PmergeMe&) = default;

};