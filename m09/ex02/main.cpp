/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:24 by apimikov          #+#    #+#             */
/*   Updated: 2024/09/04 12:24:49 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include "PmergeMe.hpp"

int setData(std::vector<unsigned int>& vec, int argc, char** argv);

int main(int argc, char** argv){
    if (1 == argc){
        std::cerr << "Error. \n";
        return (1);
    }
    std::vector<unsigned int> vec;
    if (setData(vec, argc, argv)){
        std::cerr << "Error. \n";
        return (1);
    }
    PmergeMe srt;
    matrix_t m(vec.size());
    for (size_t i = 0; i < vec.size();++i){
        m[i].push_back(vec[i]);
    }
    vector_t indexes = srt.sort(m);
    std::cout <<  "Data set\n";
    std::cout << "The result:\n";
    srt.printMatrix(m);
    std::cout << "The indexes:";
    for (auto& i : indexes){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    vector_t test = {22, 24, 28, 30, 37, 42, 43, 46, 48, 50, 51, 52, 53, 54, 55, 56, 57, 61, 63, 66, 70, 71, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 88, 89, 90, 91, 93, 96, 97, 98, 99, 100};
    if (0){
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
    return 0;
}

int setData(std::vector<unsigned int>& vec, int argc, char** argv){
    size_t pos;
    std::string str;
    int value;
    for (int i = 1; i < argc; i++){
        //std::cout << argv[i];
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


/*

*/