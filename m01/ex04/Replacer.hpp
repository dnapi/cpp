#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Replacer{
	public :
		Replacer(std::ifstream & filestream, 
			std::string toReplace,
			std::string replaceWith);
		void	findAndReplace(void);
		std::string	& getFullString(void);
		static	std::string	readAllFromFile(std::ifstream &filestream);
	private :
		std::ifstream   & _filestream;
		std::string	_fullString;
		std::string	& _toReplace;
		std::string	& _replaceWith;
};
