#pragma once

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe{
public:
//    std::vector<unsigned int> data_vec;
    std::vector<unsigned int> a;
    std::vector<unsigned int> b;
    //std::deque<unsigned int> data_deq;
    //std::deque<unsigned int> data_deq;
    PmergeMe();
    void makeTwoVectors(std::vector<unsigned int>& vec);
    void makeMainChainVector();
    ~PmergeMe() = default;
private:
    PmergeMe(const PmergeMe&) = default;
    PmergeMe& operator=(const PmergeMe&) = default;

};