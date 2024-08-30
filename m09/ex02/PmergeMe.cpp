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
}

void PmergeMe::makeMainChainVector(){
    for (size_t i = 0; i < a.size(); ++i){
        if (a[i] < b[i])
            std::swap(a[i], b[i]);
    }
    a.insert(a.begin(), b[0]);
}


vector_t PmergeMe::sortVector(vector_t& v, size_t len){
    if (2 > len){
        vector_t indexes{0, 1};
        return indexes;
    }
    if (len > v.size())
        std::cout << "[ERROR] sortVector: len is too high\n";
    vector_t indexes(len + 1);
    for (size_t i = 0; i < len + 1; ++i){
        indexes[i] = i;
    }
    size_t mid_point = len / 2;
    for (size_t i = 0; i < mid_point; ++i){
        if (!less(v[i], v[i + mid_point]))
            continue;
        std::swap(v[i], v[i + mid_point]);
        std::swap(indexes[i], indexes[i + mid_point]);
    }
    vector_t small(v.begin() + mid_point, v.end());
    v.erase(v.begin() + mid_point, v.end());
    std::cout << "small: ";
    printVector(small);
    (void)small;
    printVector(v);
    vector_t rank = sortVector(v, mid_point);
    printVector(v);
    insert(v, small, rank);
    //binaryInsertionVector(v, indexes, mid_point);
    printVector(v);
    return indexes;
}

void PmergeMe::insert(vector_t& v, vector_t& small, vector_t& rank){
    v.insert(v.begin(), small[rank[0]]);
}


void PmergeMe::binaryInsertionVector(vector_t& v, vector_t& indexes, size_t mid_point){
    unsigned int b_0 = v[mid_point];
    v.erase(v.begin() + mid_point);
    v.insert(v.begin(), b_0);
    b_0 = indexes[mid_point];
    indexes.erase(indexes.begin() + mid_point);
    indexes.insert(indexes.begin(), b_0);
}



bool PmergeMe::less(unsigned int a, unsigned int b){
    number_compare++;
    return a < b;
}

void PmergeMe::printVector(vector_t& v, size_t len){
    for (auto& i : v){
        std::cout << i << ' ';
        if (--len == 0)
            break;
    }
    std::cout << '\n';
}