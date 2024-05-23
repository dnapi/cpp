#include <iostream>
#include <fstream>
#include "Replacer.hpp"

int	main(int argc, char **argv)
{
	int		i = 0;
	if (argc != 4)
	{
		std::cout << "Number of parameters should be equal to 4" << std::endl;
		return (1);
	}

	while (++i < argc)
	{
		if (*argv[i] == '\0')
		{
			std::cout << "Arguments can't be empty strings" << std::endl;
			return (1);
		}
	}
	std::cout << "Arguments are fine" << std::endl;
	std::ifstream	input_file(argv[1]);
    	if (!input_file) 
	{
	        std::cerr << "Could not open the file for reading: " 
			<< filename << std::endl;
        	return (1);
	}
	std::string	str = Replacer::readAllFromFile(input_file);
	std::cout << str << std::endl;
	return (0);
	
}
