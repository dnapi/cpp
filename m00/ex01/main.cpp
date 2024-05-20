#include "PhoneBook.hpp"


int	main(void)
{
	PhoneBook pb;
	std::string str;
	while (1)
	{
	    std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
    	std::getline(std::cin, str);
	    std::cout << "You entered: " << str << std::endl;
		if (str == "ADD")
			pb.addEntry();
		if (str == "SEARCH")
			pb.searchEntry();
		if (str == "EXIT")
			break ;
	}
	return (0);
}
