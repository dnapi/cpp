/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:24 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/27 06:42:59 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv){
    if (1 == argc){
        std::cerr << "Error. \n";
        return (1);
    }
    std::vector<int> vec;
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
            std::cerr << "Error. \n";
            return (1);
        }
        if (pos != str.size() || value < 0){
            std::cerr << "Error. \n";
            return (1);
        }
        vec.push_back(value);
    }
    for (auto& i : vec){
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}