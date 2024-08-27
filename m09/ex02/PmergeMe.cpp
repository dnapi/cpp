#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): a(0), b(0) {}

void PmergeMe::makeTwoVectors(std::vector<unsigned int>& vec){
    size_t i = 0;
    auto it = vec.begin();
    while (it != vec.end()){
        b.push_back(*it);
        ++it;
        if (it != vec.end()){
            a.push_back(*it);
            ++it;
        }
        ++i;
    }
    std::cout << a.size() << "    " << b.size() << "\n";
}

void PmergeMe::makeMainChainVector(){
    for (size_t i = 0; i < a.size(); ++i){
        if (a[i] < b[i])
            std::swap(a[i], b[i]);
    }
    a.insert(a.begin(), b[0]);
    std::cout << '\n';
    std::cout << a.size() << "    " << b.size() << "\n";
}