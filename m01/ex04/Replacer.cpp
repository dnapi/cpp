#include "Replacer.hpp"

std::string	Replacer::readAllFromFile(std::ifstream &filestream){
	std::string	str = "";
	std::string	newline;
	
	while (std::getline(filestream, newline))
	{
		str += newline;
	//	if (filestream.eof)
	//		str += '\n';
	}
	return (str);
}
