#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter & other){
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter & other){
	(void)other;
	return *this;
}

void ScalarConverter::convert(std::string str){
	Type t = getType(str);
	if (unknownType == t|| emptyType == t){
			std::cout << "[ERROR] unknown type of the string\n";
			return ;
	}
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	castFrom(t, str, c, i, f, d);
	print(str, c, i, f, d);
}


Type ScalarConverter::getType(std::string str){
	if (str.empty())
		return emptyType;

	if (str.size() == 1 && isalpha(str[0]))
		return charType;

	size_t pos = 0;
	int flag = 0;
	int i = 0;
	try {
		i = std::stoi(str, &pos);
	}
	catch (const std::invalid_argument& e) {
		flag = 1;
	}
	catch (const std::out_of_range& e) {
		flag = 2;
    }
	if (pos == str.size())
		return intType;

	flag = 0;
	float f = 0;
	try {
		f = std::stof(str, &pos);
	}
	catch (const std::invalid_argument& e) {
		flag = 1;
	}
	catch (const std::out_of_range& e) {
		flag = 2;
    }
	if (str.back() == 'f' && pos + 1 == str.size())
		return floatType;

	flag = 0;
	double d = 0;
	try {
		d = std::stod(str, &pos);
	}
	catch (const std::invalid_argument& e) {
		flag = 1;
	}
	catch (const std::out_of_range& e) {
		flag = 2;
    }
	if (pos == str.size())
		return doubleType;
	
	(void)flag;
	(void)i;
	(void)f;
	(void)d;

	return unknownType;
}

void ScalarConverter::castFrom(Type t, std::string& str, char& c, int& i, float& f, double& d){
	switch (t){
		case charType:
			std::cout << "This is char\n";
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case intType:
			std::cout << "This is int\n";
			i = std::stoi(str);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case floatType:
			std::cout << "This is float\n";
			f = std::stof(str);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case doubleType:
			std::cout << "This is double\n";
			d = std::stod(str);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		case emptyType:
			return ;
		case unknownType:
			return ;
	}
}


void ScalarConverter::print(std::string& str, char c, int i, float f, double d){
	if (isPseudo(str))
		std::cout << "char: impossible\n";
	else if (32 < c && c < 127)
		std::cout << "char: " << c  << "\n";
	else 
		std::cout << "char: Non displayable\n";
	if (isPseudo(str))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";
	std::cout 
		<< "float: " << f << "\n"
		<< "double: " << d << "\n";
}

bool ScalarConverter::isPseudo(std::string& str){
	if (str == "nan" || str == "nanf" ||
		str == "+inff" || str == "-inff" ||
		str == "+inf" || str == "-inf")
		return true;
	return false;
}