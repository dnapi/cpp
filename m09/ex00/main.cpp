/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:26:42 by apimikov          #+#    #+#             */
/*   Updated: 2024/09/08 15:32:22 by apimikov         ###   ########.fr       */
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
    BitcoinExchange btc;
    if (btc.makeData("data.csv"))
        return 1;
    if (btc.readInput(argv[1]))
        return 1;
    return 0;
}