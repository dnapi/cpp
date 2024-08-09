#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>

enum Type {emptyType, pseudoType, charType, intType,  floatType,  doubleType, unknownType};

class ScalarConverter{
	public:
		static void convert(std::string);
		static Type getType(std::string);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter& operator=(const ScalarConverter &);
		static void print(char, int, float, double);
		static void printChar(char);
		static bool isChar(const std::string&);
		static void toChar(const std::string&);
		static bool isInt(const std::string&);
		static void toInt(const std::string&);
};

#endif
