#include "PhoneBook.hpp"


int	main(void)
{
	PhoneBook pb;
	std::string str;

	while (1)
	{
	    std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
    	if (!std::getline(std::cin, str))
		{
			std::cout << "You have entered EOF. Program is terminated." << std::endl;
			break ;
		}
	    //std::cout << "You entered: " << str << std::endl;
		if (str == "ADD")
			pb.addEntry();
		else if (str == "SEARCH")
			pb.searchEntry();
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Command: " << str << "is not supported." << std::endl;
	}
	return (0);
}
