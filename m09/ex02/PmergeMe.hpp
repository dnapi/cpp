#pragma once

#include <iostream>
#include <vector>
#include <deque>

using vector_t = std::vector<unsigned int>;
using vector_pair = std::vector<std::pair<unsigned int, unsigned int>>;
using vector_it = std::vector<unsigned int>::iterator;

using matrix_t = std::vector<std::vector<unsigned int>>;
using matrix_it = std::vector<std::vector<unsigned int>>::iterator;

class PmergeMe{
public:
//    std::vector<unsigned int> data_vec;
    vector_t a;
    vector_t b;
    size_t number_compare = 0;
    size_t number_iterations = 0;
    //std::deque<unsigned int> data_deq;
    //std::deque<unsigned int> data_deq;
    PmergeMe();
    //vector_t sortVector(vector_t& v);
    //vector_t sortVectorPair(vector_pair& v);
    vector_t sort(matrix_t& v);
    void makeTwoVectors(vector_t& vec);
    void makeMainChainVector();
    ~PmergeMe() = default;
    void printMatrix(matrix_t& v, size_t len = 20);
    void printVector(vector_t& v, size_t len = 20);
    void printVectorTuple(vector_pair& v, size_t len = 20);
    void binaryInsertion(matrix_t& m, matrix_it first, matrix_it last, vector_t& value);
private:
    bool less(unsigned int a, unsigned int b);
    void insert(matrix_t& main, matrix_t& small, vector_t& rank);
    PmergeMe(const PmergeMe&) = default;
    PmergeMe& operator=(const PmergeMe&) = default;
};