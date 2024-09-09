/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:50 by apimikov          #+#    #+#             */
/*   Updated: 2024/09/09 10:10:16 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::sortDeque(deque_t& deq){
    deque2d_t m(deq.size());
    for (size_t i = 0; i < deq.size();++i){
        m[i].push_back(deq[i]);
    }
    sortDeque2D(m);
    for (size_t i = 0; i < m.size();++i){
        deq[i] = m[i][0];
    }
}

void PmergeMe::sortVector(vector_t& vec){
    matrix_t m(vec.size());
    for (size_t i = 0; i < vec.size();++i){
        m[i].push_back(vec[i]);
    }
    sortMatrix(m);
    for (size_t i = 0; i < vec.size();++i)
        vec[i] = m[i][0];
}

vector_t PmergeMe::sortMatrix(matrix_t& m){
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
    vector_t rank_next = sortMatrix(m);
    insert(m, small, rank_next);
    vector_t rank(m.size() + 1);
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
        size_t i = small.size() - extra_elem;
        i = i > t_k ? t_k : i;
        for (; i > t_k_prev; --i){  // loop inside the group
            main_work_end = t_k < small.size() - extra_elem
                ? main.begin() + (1 << k) - 1  // (1 << k)  == 2 ** k
                : main.end();
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

void PmergeMe::printVector(vector_t& v, size_t len){
    for (auto& i : v){
        std::cout << i << ' ';
        if (--len == 0) 
            break;
    }
    std::cout << '\n';
}

void PmergeMe::printDeque(deque_t& v, size_t len){
    for (auto& i : v){
        std::cout << i << ' ';
        if (--len == 0) 
            break;
    }
    std::cout << '\n';
}


/*
the following is duplication of the code, as 
templates was not allowed for this project
*/

deque_t PmergeMe::sortDeque2D(deque2d_t& m){
    number_iterations++;
    //size_t current_iteration = number_iterations;
    size_t len = m.size();
    if (2 > len){
        deque_t indexes{0, 1};
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
    deque2d_t small(m.begin() + mid_point, m.end());
    m.erase(m.begin() + mid_point, m.end());
    deque_t rank_next = sortDeque2D(m);
    insertDeque(m, small, rank_next);
    deque_t rank(m.size() + 1);
    for (size_t i = 0; i < m.size(); ++i){
        rank[i] = m[i].back();
        m[i].pop_back();
    }
    return rank;
}

void PmergeMe::insertDeque(deque2d_t& main, deque2d_t& small, deque_t& rank){
    size_t extra_elem = small.size() - main.size();
    main.insert(main.begin(), small[rank[0]]);
    size_t k = 2;
    size_t t_k = 3;
    size_t t_k_prev = 1;
    auto main_work_end = main.begin();
    while (t_k_prev <= small.size() - extra_elem){    // loop over groups
        size_t i = small.size() - extra_elem;
        i = i > t_k ? t_k : i;
        for (; i > t_k_prev; --i){  // loop inside the group
            main_work_end = t_k < small.size() - extra_elem
                ? main.begin() + (1 << k) - 1  // (1 << k)  == 2 ** k
                : main.end();
            binaryInsertionDeque(main, main.begin(), main_work_end, small[rank[i - 1]]);
        }
        t_k_prev = t_k;
        ++k;
        t_k = (1 << k) - t_k_prev;  // (1 << k)  == 2 ** k
    }
    if (extra_elem)
        binaryInsertionDeque(main, main.begin(), main.end(), small.back());
}


void PmergeMe::binaryInsertionDeque(deque2d_t& m, deque2d_it first, deque2d_it last, deque_t& value){
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
    auto mid = first + (last - first) / 2;
    if (!less(value[0], (*mid)[0])){
        if (1 == last - mid)
            m.insert(last, value);
        else
            binaryInsertionDeque(m, mid + 1, last, value);
        return ;
    }
    if (value[0] < (*mid)[0]){
        binaryInsertionDeque(m, first, mid, value);
        return ;
    }
    m.insert(mid, value);
}