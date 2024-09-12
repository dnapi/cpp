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
    if (!std::getline(file, line)){
        std::cerr << "Error: File  " << filename << " is incorrectly formated\n";
        return 1;
    }

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
        std::cerr << "[ERROR] Wrong data file format. Invalide rate.\n";
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "[ERROR] Wrong data file format. Out of range.\n";
        return 1;
    }
    data[date] = value;
    return 0;
}

double BitcoinExchange::getRate(std::string date){
    auto it = data.upper_bound(date);
    if (it == data.begin()){
        std::cerr << "Error: oldest date is " << data.begin()->first << "\n";
        return -1;
    }
    --it;
    return it->second;
}

int BitcoinExchange::readInput(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()){
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }
    std::string line;
    if (!std::getline(file, line)){
        std::cerr << "Error: File is empty " << filename << std::endl;
    }
    while (std::getline(file, line)){
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
        value = stod(matches[2]);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: invalid value.\n";
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: value is out of double range.\n";
        return 1;
    }
    if (value < 0){
        std::cerr << "Error: not a positive number.\n";
        return 1;
    }
    if (value > 1000){
        std::cerr << "Error: too large number.\n";
        return 1;
    }
    if (!validateDate(date)){
        std::cerr << "Error: invalid date: " << date <<".\n";
        return 1;
    }
    double rate = getRate(date);
    if (rate >= 0)
        std::cerr << date << " => " << value << " = " << getRate(date) * value << "\n";
    return 0; 
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::validateDate(const std::string& date) {
    std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    if (!std::regex_match(date, datePattern)) {
        return false;
    }
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    return isValidDate(year, month, day);
}
