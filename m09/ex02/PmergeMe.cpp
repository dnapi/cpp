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
    //size_t current_iteration = number_iterations;
    //std::cout << "-------  Iteration " << current_iteration << "------\n";
    number_iterations++;
    size_t len = m.size();
    if (2 > len){
        vector_t indexes{0, 1};
        return indexes;
    }
    for (size_t i = 0; i < len; ++i){
        m[i].push_back(i);
    }
    size_t mid_point = len / 2;
    size_t rest_element = len % 2;
    (void)rest_element;
    for (size_t i = 0; i < mid_point; ++i){
        if (less(m[i][0], m[i + mid_point][0]))
            std::swap(m[i], m[i + mid_point]);
    }
    matrix_t small(m.begin() + mid_point, m.end());
    m.erase(m.begin() + mid_point, m.end());
    vector_t rank_next = sort(m);
    insert(m, small, rank_next);
    vector_t rank(m.size() + 1);
    rank.back() = len;
    for (size_t i = 0; i < m.size(); ++i){
        rank[i] = m[i].back();
        m[i].pop_back();
    }
    return rank;
}

void PmergeMe::insert(matrix_t& main, matrix_t& small, vector_t& rank){
    size_t extra_elem = small.size() - main.size();
    main.insert(main.begin(), small[rank[0]]);
    size_t k = 2;
    size_t t_k = 3;
    size_t t_k_prev = 1;
    auto main_work_end = main.begin();
    while (t_k_prev <= small.size() - extra_elem){    // loop over groups
        // std::cout << "   t_k=" << t_k << "\n";
        // std::cout << "   t_k_prev=" << t_k_prev << "\n";
        // std::cout << "   k=" << k << "\n";
        // std::cout << "   2 ** k=" << (1 << k) << "\n";
        // std::cout << "extra_element" << extra_elem << "\n";
        main_work_end = t_k > small.size() - extra_elem? 
                main.begin() + (1 << k) - 1  // (1 << k)  == 2 ** k
            :   main.end();
        // for (size_t i = t_k; i > t_k_prev; --i){  // loop inside the group
        //     if (i > small.size() - extra_elem)
        //         continue;
        size_t i = small.size() - extra_elem;
        i = i > t_k ? t_k : i;
        for (; i > t_k_prev; --i){  // loop inside the group
            binaryInsertion(main, main.begin(), main_work_end, small[rank[i - 1]]);
        }
        t_k_prev = t_k;
        ++k;
        t_k = (1 << k) - t_k_prev;  // (1 << k)  == 2 ** k
    }
    if (extra_elem)
        binaryInsertion(main, main.begin(), main.end(), small.back());
}


void PmergeMe::binaryInsertion(matrix_t& m, matrix_it first, matrix_it last, vector_t& value){
    // std::cout << "first=\n";
    // printVector(*first);
    // std::cout << "  last-1=\n";
    // printVector(*(last - 1));
    if (last <= first)
        return ;
    if (last - first == 1){
        if (value[0] > (*first)[0]){
            m.insert(last, value);
            return ;
        }
        m.insert(first, value);
        return;
    }
    matrix_it mid = first + (last - first) / 2;
    if (!less(value[0], (*mid)[0])){
        if (1 == last - mid)
            m.insert(last, value);
        else
            binaryInsertion(m, mid + 1, last, value);
        return ;
    }
    if (value[0] < (*mid)[0]){
        binaryInsertion(m, first, mid, value);
        return ;
    }
    m.insert(mid, value);
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
    for (size_t i = 0; i < v.size(); ++i){
        std::cout << "i=" << i << ":";
        for (size_t j = 0; j < v[i].size(); ++j){
           std::cout << v[i][j] << ' ';
           if (j >= len)
              break;
        }
        std::cout << '\n';
        if (i >= len)
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


