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

vector_t PmergeMe::sort(matrix_t& m){
    std::cout << "-------  Iteration " << number_iterations++ << "------\n";
    size_t len = m.size();
    if (2 > len){
        vector_t indexes{0, 1};
        return indexes;
    }
    vector_t indexes(len + 1);
    for (size_t i = 0; i < len; ++i){
        //m[i].push_back(i);
        indexes[i] = i;
    }
    size_t mid_point = len / 2;
    size_t rest_element = len % 2;
    (void)rest_element;
    for (size_t i = 0; i < mid_point; ++i){
        if (!less(m[i][0], m[i + mid_point][0]))
            continue;
        std::swap(m[i], m[i + mid_point]);
        std::swap(indexes[i], indexes[i + mid_point]);
    }
    matrix_t small(m.begin() + mid_point, m.end());
    m.erase(m.begin() + mid_point, m.end());
    {
        std::cout << "small: \n";
        printMatrix(small);
        std::cout << "main: \n";
        printMatrix(m);
    }
    vector_t rank = sort(m);
    std::cout << "main after recursive sort: \n";
    printMatrix(m);
    /*
    vector_t indexes_ranked(indexes.size());
    vector_pair small_ranked(small.size());
    indexes_ranked.back() = indexes.back();
    for (size_t i = 0; i < mid_point; ++i){
        small_ranked[i] = small[rank[i]];
        indexes_ranked[i] = indexes[rank[i]];
        indexes_ranked[i + mid_point] = indexes[rank[i] + mid_point];
    }
    insert(v, small_ranked, indexes_ranked);
    //binaryInsertionVector(v, indexes, mid_point);
    */
    return indexes;
}

/*
vector_t PmergeMe::sortVector(vector_t& v){
    size_t len = v.size();
    if (2 > len){
        vector_t indexes{0, 1};
        return indexes;
    }
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
    vector_t rank = sortVector(v);
    printVector(v);
    vector_t indexes_ranked(indexes.size());
    vector_t small_ranked(small.size());
    indexes_ranked.back() = indexes.back();
    for (size_t i = 0; i < mid_point; ++i){
        small_ranked[i] = small[rank[i]];
        indexes_ranked[i] = indexes[rank[i]];
        indexes_ranked[i + mid_point] = indexes[rank[i] + mid_point];
    }
    insert(v, small_ranked, indexes_ranked);
    //binaryInsertionVector(v, indexes, mid_point);
    printVector(v);
    return indexes;
}
*/

/*
void PmergeMe::insert(vector_t& v, vector_t& small, vector_t& indexes, vector_t& rank){
    v.insert(v.begin(), small[rank[0]]);
    (void)indexes;
}
*/

/*
size_t PmergeMe::insertPosition(vector_t& v, size_t begin, size_t end, unsigned int value){
    if (begin == end)
        return begin;
    size_t mid_point = begin + (end - begin) / 2;
    if (value < v[mid_point])
*/
/*
    unsigned int b_0 = v[mid_point
    v.erase(v.begin() + mid_point);
    v.insert(v.begin(), b_0);
    b_0 = indexes[mid_point];
    indexes.erase(indexes.begin() + mid_point);
    indexes.insert(indexes.begin(), b_0);
*/


void PmergeMe::binaryInsertionVector(vector_t& v, vector_t& indexes, size_t mid_point){
    unsigned int b_0 = v[mid_point];
    v.erase(v.begin() + mid_point);
    v.insert(v.begin(), b_0);
    b_0 = indexes[mid_point];
    indexes.erase(indexes.begin() + mid_point);
    //indexes.insert(indexes.begin(), b_0);
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

void PmergeMe::printMatrix(matrix_t& v, size_t len){
    for (size_t j = 0; j < v[0].size(); ++j){
        for (size_t i = 0; i < v.size(); ++i){
           std::cout << v[i][j] << ' ';
           if (i >= len)
              break;
        }
        std::cout << '\n';
        if (j >= len)
            break;
    }
    std::cout << '\n';
}


void PmergeMe::printVectorTuple(vector_pair& v, size_t len){
    std::cout << "   values :";
    for (auto& i : v){
        std::cout << i.first << ' ';
        if (--len == 0)
            break;
    }
    std::cout << '\n';
    std::cout << "   indexes:";
    for (auto& i : v){
        std::cout << i.second << ' ';
        if (--len == 0)
            break;
    }
    std::cout << '\n';
}