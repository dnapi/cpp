/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:37:27 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/22 16:18:57 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>

class BitcoinExchange{
public:
    BitcoinExchange() = default;
    ~BitcoinExchange() = default;
    int makeData(const std::string& filename);
    int addDataEntry(std::string line);
    double getRate(std::string);
    int readInput(const std::string& filename);
    int calcPrice(std::string line);
private:
    BitcoinExchange(const BitcoinExchange&) = default;
    BitcoinExchange& operator=(const BitcoinExchange&) = default;
    std::map<std::string, double> data;
};