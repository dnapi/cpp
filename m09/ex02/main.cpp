/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:24 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/27 06:59:31 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

int setData(std::vector<int>& vec, int argc, char** argv);

int main(int argc, char** argv){
    if (1 == argc){
        std::cerr << "Error. \n";
        return (1);
    }
    std::vector<int> vec;
    if (setData(vec, argc, argv)){
        std::cerr << "Error. \n";
        return (1);
    }
    for (auto& i : vec){
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}

int setData(std::vector<int>& vec, int argc, char** argv){
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
        if (pos != str.size() || value < 0){
            return (1);
        }
        vec.push_back(value);
    }
	return 0;
}
