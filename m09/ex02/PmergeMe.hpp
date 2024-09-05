#pragma once

#include <iostream>
#include <vector>
#include <deque>

using vector_t = std::vector<unsigned int>;
using matrix_t = std::vector<std::vector<unsigned int>>;
using matrix_it = std::vector<std::vector<unsigned int>>::iterator;
using deque_t = std::deque<unsigned int>;
using deque2d_t = std::deque<std::deque<unsigned int>>;
using deque2d_it = std::deque<std::deque<unsigned int>>::iterator;

class PmergeMe{
public:
    bool red_flag = 0;
    size_t number_compare = 0;
    size_t number_iterations = 0;
    void sortVector(vector_t& vec);
    vector_t sortMatrix(matrix_t& v);
    void insert(matrix_t& main, matrix_t& small, vector_t& rank);
    void binaryInsertion(matrix_t& m, matrix_it first, matrix_it last, vector_t& value);
    void sortDeque(deque_t& deq);
    deque_t sortDeque2D(deque2d_t& m);
    void insertDeque(deque2d_t& main, deque2d_t& small, deque_t& rank);
    void binaryInsertionDeque(deque2d_t& m, deque2d_it first, deque2d_it last, deque_t& value);
    void printMatrix(matrix_t& v, size_t len = 200);
    void printVector(vector_t& v, size_t len = 200);
    void printDeque(deque_t& v, size_t len = 200);
    PmergeMe() = default;
    ~PmergeMe() = default;
private:
    bool less(unsigned int a, unsigned int b);
    PmergeMe(const PmergeMe&) = default;
    PmergeMe& operator=(const PmergeMe&) = default;
};