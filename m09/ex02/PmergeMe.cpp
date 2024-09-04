#include "PmergeMe.hpp"

//PmergeMe::PmergeMe(): {}

vector_t PmergeMe::sort(matrix_t& m){
    size_t current_iteration = ++number_iterations;
    std::cout << "------------  Iteration " << current_iteration << "\n";
    size_t len = m.size();
    if (2 > len){
        vector_t indexes{0, 1};
        return indexes;
    }
    for (size_t i = 0; i < len; ++i){
        m[i].push_back(i);
    }
    size_t mid_point = len / 2;
    for (size_t i = 0; i < mid_point; ++i){
        if (less(m[i][0], m[i + mid_point][0]))
            std::swap(m[i], m[i + mid_point]);
    }
    matrix_t small(m.begin() + mid_point, m.end());
    m.erase(m.begin() + mid_point, m.end());
    vector_t rank_next = sort(m);
    std::cout << "------------  Iteration " << current_iteration << "sorted\n";
    insert(m, small, rank_next);
    std::cout << "------------  Iteration " << current_iteration << "inserted\n";
    std::cout << "m.size()=" << m.size() << "\n";
    printMatrix(m);
    vector_t rank(m.size() + 1);
    for (size_t i = 0; i < m.size(); ++i){
        std::cout << "i=" << i << "\n";
        rank[i] = m[i].back();
        std::cout << "size m[i]=" << m[i].size() << "\n";
        m[i].pop_back();
    }
    std::cout << "------------  Iteration " << current_iteration << "ended\n";
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
        main_work_end = t_k > small.size() - extra_elem? 
                main.begin() + (1 << k) - 1  // (1 << k)  == 2 ** k
            :   main.end();
        size_t i = small.size() - extra_elem;
        i = i > t_k ? t_k : i;
        for (; i > t_k_prev; --i)  // loop inside the group
            binaryInsertion(main, main.begin(), main_work_end, small[rank[i - 1]]);
        t_k_prev = t_k;
        ++k;
        t_k = (1 << k) - t_k_prev;  // (1 << k)  == 2 ** k
    }
    if (extra_elem)
        binaryInsertion(main, main.begin(), main.end(), small.back());
}


void PmergeMe::binaryInsertion(matrix_t& m, matrix_it first, matrix_it last, vector_t& value){
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