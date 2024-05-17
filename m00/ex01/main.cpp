#include "Contact.hpp"

int	main(void)
{
	Contact c;
	std::string str;
	for (int i = 0; i < 3; i++)
	{
	    std::cout << "Please enter a line of text: ";
    	std::getline(std::cin, str);
	    std::cout << "You entered: " << str << std::endl;
	}
//	instance.foo = 42;
//	std::cout << "foo = " << instance.foo << std::endl;
//	instance.boo();

	return (0);
}
