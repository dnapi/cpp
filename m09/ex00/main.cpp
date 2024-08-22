/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:26:42 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/22 16:54:02 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "BitcoinExchange.hpp"


int main(int argc, char** argv){
    if (argc != 2){
        std::cout << "Please provide one file name as an argument\n";
        return (1);
    }
    (void)argv;
    /*
    std::string filename = argv[1];
    size_t position_ext = std::string(filename).rfind('.');
    std::string file_extension = filename.substr(position_ext);
    if (file_extension != ".csv"){
        std::cout << "Please provide one file name with extension .csv\n";
        return (1);
    }
    */
    
    BitcoinExchange btc;
    btc.makeData("data.csv");
    btc.readInput(argv[1]);


    // std::cout << btc.getRate("2022-03-22") << "\n";
    // std::cout << btc.getRate("2022-03-23") << "\n";
    // std::cout << btc.getRate("2022-03-24") << "\n";
    // std::cout << btc.getRate("2022-03-25") << "\n";
    // std::cout << btc.getRate("2022-03-29") << "\n";
    // std::cout << btc.getRate("2022-05-30") << "\n";


    // std::cout << btc.getRate("2009-01-01") << "\n";
    // std::cout << btc.getRate("2009-01-02") << "\n";

    return 0;
}