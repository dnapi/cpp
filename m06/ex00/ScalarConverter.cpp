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

void ScalarConverter::print(char c, int i, float f, double d){
	std::cout << "char: " << c 
		<< "\nint: " << i
		<< "\nfloat: " << f 
		<< "\ndouble: " << d 
		<< "\n";
}

bool ScalarConverter::isChar(const std::string & str){
	if (!(str.size() != 1 && isalpha(str[0])))
		return false;
	return true;
}

void ScalarConverter::toChar(const std::string & str){
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	print(c, i, f, d);
}

void ScalarConverter::convert(const std::string str){
	if (isChar(str))
		toChar(str);
	size_t pos = 0;
	try {
		double num = std::stod(str, &pos);
        	std::cout << "The double value is: " << num << std::endl;
	}
	catch (const std::invalid_argument& e) {
        	std::cout << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e) {
        	std::cout << "Out of range: " << e.what() << std::endl;
    	}
	if (pos != std::string::npos)
		std::cout << "remainings=" << str.substr(pos) << "\n";
	double nan_value = std::nan("");
	double pos_inf = std::numeric_limits<double>::infinity();
	double neg_inf = -std::numeric_limits<double>::infinity();
	std::cout << "Nan=" << nan_value << "\n";
	std::cout << "+inf=" << pos_inf << "\n";
	std::cout << "-inf=" << neg_inf << "\n";
}
