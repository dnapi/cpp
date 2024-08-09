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

/*



<<<<<<< Updated upstream
=======
void ScalarConverter::print(char c, int i, float f, double d){
	printChar(c);
	std::cout
		<< "\nint: " << i
		<< "\nfloat: " << f 
		<< "\ndouble: " << d 
		<< "\n";
}
>>>>>>> Stashed changes

bool ScalarConverter::isPseudo(const std::string & str){
	for (auto& s: {"nan", "nanf", "-inff", "+inff", "-inf", "+inf"})
	{
		if (str == s)
			return true;
		else
			continue;
	}
	return false;
}
void ScalarConverter::doPseudo(const std::string & str){
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (str == "nanf")
	{
		float f = std::nan("");
		double d = static_cast<double>(f);
		d = f; //ok
		f = d; //ko
	}
	if (str == "nanf")
	{
		float f = std::nan("");
		double d = static_cast<double>f;
	}
	if (str == "nan" | str == "nanf")
	{
		float f = std::nan("");
		double d = std::nan("");
	}
	else if (str == "+inf" | str == "+inff")
	{
		float f = std::numeric_limits<float>::infinity();
		double d = std::numeric_limits<double>::infinity();
	}
	double neg_inf = -std::numeric_limits<double>::infinity();
	toChar(str);
	return true;
}

bool ScalarConverter::isChar(const std::string & str){
	if (str.size() != 1)
		return false;
	if (!isalpha(str[0]))
		return false;
	toChar(str);
	return true;
}

void ScalarConverter::toChar(const std::string & str){
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	print(c, i, f, d);
}

bool ScalarConverter::isInt(const std::string & str){
	if (!((str[0] == '-') | isdigit(str[0])))
		return false;
	size_t pos = 0;
	int i = 0;
	try {
		i = std::stoi(str, &pos);
        	std::cout << "The int value is: " << i << std::endl;
	}
	catch (const std::invalid_argument& e) {
        	std::cout << "Int: Invalid argument: " << e.what() << std::endl;
		return false;
	}
	catch (const std::out_of_range& e) {
        	std::cout << "Int: Out of range: " << e.what() << std::endl;
		return false;
    	}
	if (pos != std::string::npos)
	{
		std::cout << "int remainings=" << str.substr(pos) << "\n";
		return false;
	}
	char c = 0;
	if (i > 31 && i < 127)
	{
		c = static_cast<char>(i);
	}
//	else (i < 0 || i > 127)

	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	print(c, i, f, d);
	return true;
}

void ScalarConverter::toInt(const std::string & str){
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	print(c, i, f, d);
}

*/

void ScalarConverter::print(char c, int i, float f, double d){
	//printChar(c); 
	std::cout << "char: " << c;
	std::cout 
		<< "\nint: " << i
		<< "\nfloat: " << f 
		<< "\ndouble: " << d 
		<< "\n";
}

/*
void ScalarConverter::printChar(char c)
{
	std::cout << "char: ";
	if (c)
		std::cout << c;
	else
		std::cout << "Non displayable";
}*/


Type ScalarConverter::getType(std::string str){
	if (str.empty())
		return emptyType;

	if (str.size() == 1 && isalpha(str[0]))
		return charType;

	if (str == "nan" || str == "nanf" || 
		str == "+inff" || str == "-inff" ||
		str == "+inf" || str == "-inf")
		return pseudoType;

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

void ScalarConverter::convert(const std::string str){
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	Type t = getType(str);
	switch (t){
		case emptyType:
			std::cout << "[ERROR] nothing to convert\n";
			return ;
		case pseudoType:
			std::cout << "pseudoType\n";
			break;
		case charType:
			std::cout << "charType\n";
			break;
		case intType:
			std::cout << "intType\n";
			break;
		case floatType:
			std::cout << "floatType\n";
			f = std::stof(str);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			print(c, i, f, d);
			break;
		case doubleType:
			std::cout << "doubleType\n";
			break;
		case unknownType:
			std::cout << "[ERROR] unknown type of the string\n";
			return ;
	}
	(void)c;
	(void)i;
	(void)f;
	(void)d;
	return ;
/*	if (isChar(str))
		return ;
	if (isInt(str))
		return ;
	*/
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
