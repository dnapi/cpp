#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("Gooddy");
	a.attack("Baddy");
	a.takeDamage(3);
	a.beRepaired(4);
	a.beRepaired(4);
	return (0);
}	
