#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Gooddy");
	a = ClapTrap("Foo");
	a.attack("Baddy");
	a.takeDamage(3);
	a.beRepaired(4);
	a.beRepaired(4);

	ScavTrap st("Robot");
	st.attack("a door");
	st.takeDamage(42);
	st.beRepaired(10);

	return (0);
}	
