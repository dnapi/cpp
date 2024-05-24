#include <iostream>
#include <fstream>
#include "Replacer.hpp"

int	main(int argc, char **argv)
{
	int		i = 0;
	if (argc != 4)
	{
		std::cout << "Number of parameters should be equal to 3" << std::endl;
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
			<< argv[1] << std::endl;
        	return (1);
	}
	std::string	outfile_name = argv[1];
	outfile_name += ".replace";
	std::ofstream	outputFile(outfile_name);
	if (!outputFile) 
	{
	    std::cout << "Could not open the file for writing: " 
		<< outfile_name << std::endl;
	    return (1);
	}	
	Replacer rep = Replacer(input_file, argv[2], argv[3]);
	input_file.close();
	rep.findAndReplace();
	std::cout << rep.getFullString();
	outputFile << rep.getFullString();
	outputFile.close();
	return (0);
}
