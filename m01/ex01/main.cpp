#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	int n = 10;
	Zombie *z; 
	std::cout << "starting zombieHorde" << std::endl;
	z = zombieHorde(n, "Zozo");
	while (n-- >0)
		z[n].announce();
	delete [] z;
	return (0);
}
