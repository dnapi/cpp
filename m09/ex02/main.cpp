/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:24 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/29 11:33:33 by apimikov         ###   ########.fr       */
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
    srt.makeTwoVectors(vec);
    srt.makeMainChainVector();
    vector_t original_vec = vec;
    vector_t indexes = srt.sortVector(vec, vec.size());

    std::cout << "The indexes:";
    for (auto& i : indexes){
        std::cout << i << ' ';
    }
    std::cout << '\n';
    
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
