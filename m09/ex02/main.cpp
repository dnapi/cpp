/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:24 by apimikov          #+#    #+#             */
/*   Updated: 2024/09/08 16:37:51 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include "PmergeMe.hpp"

int setData(std::vector<unsigned int>& vec, int argc, char** argv);
int setData(deque_t& deq, int argc, char** argv);
bool isSorted(const vector_t& vec);
bool isSorted(const deque_t& vec);

int main(int argc, char** argv){
    if (1 == argc){
        std::cerr << "Error. \n";
        return (1);
    }
    {
        auto start = std::chrono::steady_clock::now();
        std::vector<unsigned int> vec;
        if (setData(vec, argc, argv)){
            std::cerr << "Error. \n";
            return (1);
        }
        PmergeMe srt;
        std::cout << "Before: ";
        srt.printVector(vec, vec.size());
        srt.sortVector(vec);
        std::cout << "After: ";
        srt.printVector(vec, vec.size());
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Time to process a range of " << argc - 1
            <<" elements with std::vector : " << elapsed_seconds.count() * 1000000 << "us\n";
        if (!isSorted(vec))
            std::cout << "NOT SORTED\n";
    }
    
    {
        auto start = std::chrono::steady_clock::now();
        std::deque<unsigned int> deq;
        if (setData(deq, argc, argv)){
            std::cerr << "Error. \n";
            return (1);
        }
        PmergeMe srt;
        srt.sortDeque(deq);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Time to process a range of " << argc - 1
            <<" elements with std::deque : " << elapsed_seconds.count() * 1000000 << "us\n";
        std::cout << "Number  of comparisons = " << srt.number_compare << " \n";
        if (!isSorted(deq))
            std::cout << "NOT SORTED\n";
    }

    double sum = 0.0;
    for (int k = 2; k <= argc; ++k) {
        sum += std::ceil(std::log2(3 * k / 4));
    }
    std::cout << "Estimated number of comparisons is: " << sum << std::endl;

    return 0;
}

int setData(std::vector<unsigned int>& vec, int argc, char** argv){
    size_t pos;
    std::string str;
    int value;
    for (int i = 1; i < argc; i++){
        str = argv[i];
        try{
            value = std::stoi(str, &pos);
        }
        catch (...){
            return (1);
        }
        if (pos != str.size() || value <= 0)
            return (1);
        vec.push_back(value);
    }
	return 0;
}

int setData(deque_t& deq, int argc, char** argv){
    size_t pos;
    std::string str;
    int value;
    for (int i = 1; i < argc; i++){
        str = argv[i];
        try{
            value = std::stoi(str, &pos);
        }
        catch (...){
            return (1);
        }
        if (pos != str.size() || value <= 0)
            return (1);
        deq.push_back(value);
    }
	return 0;
}

bool isSorted(const vector_t& vec){
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSorted(const deque_t& vec){
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

/*
if (0){
        vector_t test = {22, 24, 28, 30, 37, 42, 43, 46, 48, 50, 51, 52, 53, 54, 55, 56, 57, 61, 63, 66, 70, 71, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 88, 89, 90, 91, 93, 96, 97, 98, 99, 100};
        std::cout << "\n\n ----- Binary insert test ---- \n";
        matrix_t mmm(test.size());
        vector_t vvv = {1};
        for (size_t i = 0; i < mmm.size(); ++i){
            vvv[0] = test[i];
            mmm[i] = vvv;
        }
        srt.printMatrix(mmm);
        vector_t value = {95};
        srt.binaryInsertion(mmm, mmm.begin(), mmm.end(), value);
        //srt.binaryInsertion(mmm, mmm.begin(), mmm.end(), value);
        //value = {0};
        //srt.binaryInsertion(mmm, mmm.begin(), mmm.end(), value);
        //value = {3};
        //srt.binaryInsertion(mmm, mmm.begin(), mmm.end(), value);
        //value = {11};
        //srt.binaryInsertion(mmm, mmm.begin(), mmm.end(), value);
        srt.printMatrix(mmm);
    }
*/