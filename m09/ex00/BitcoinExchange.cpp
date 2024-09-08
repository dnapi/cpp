/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:27:47 by apimikov          #+#    #+#             */
/*   Updated: 2024/09/08 15:34:25 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int BitcoinExchange::makeData(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (addDataEntry(line))
            return 1;
    }
    file.close();
    return 0;
}

int BitcoinExchange::addDataEntry(std::string line){
    std::regex pattern(R"((\d{4})-(\d{2})-(\d{2}),(\d+(\.\d+)?)?)");
    std::smatch matches;
    if (!std::regex_match(line, matches, pattern))
        return 1;
    std::string date = line.substr(0 ,10);
    double value = 0;
    try {
        value = stod(line.substr(11));
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[ERROR] Wrong data file format. Invalide rate.\n";
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cout << "[ERROR] Wrong data file format. Out of range.\n";
        return 1;
    }
    data[date] = value;
    return 0;
}

double BitcoinExchange::getRate(std::string date){
    auto it = data.upper_bound(date);
    if (it == data.begin()){
        std::cout << "Error: oldest date is " << data.begin()->first << "\n";
        return -1;
    }
    --it;
    return it->second;
}

int BitcoinExchange::readInput(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        calcPrice(line);
    }
    file.close();
    return 0;
}

int BitcoinExchange::calcPrice(std::string line){
    std::regex pattern(R"((\d{4}-\d{2}-\d{2})\s*\|\s*(-?\d+(\.\d+)?))");
    std::smatch matches;
    if (!std::regex_match(line, matches, pattern))
    {
        std::cout << "Error: bad input => " << line << "\n";
        return 1;
    }
    std::string date = line.substr(0 ,10);
    double value = 0;
    try {
        value = stod(matches[2] );
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: invalid value.\n";
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Error: value is out of double range.\n";
        return 1;
    }
    if (value < 0){
        std::cout << "Error: not a positive number.\n";
        return 1;
    }
    if (value > 2147483647){
        std::cout << "Error: too large number.\n";
        return 1;
    }
    double rate = getRate(date);
    if (rate >= 0)
        std::cout << date << " => " << value << " = " << getRate(date) * value << "\n";
    return 0; 
}