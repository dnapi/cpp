#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
	st.guardGate();

	FragTrap ft("Chupacabra");
	ft.attack("Robot");
	ft.takeDamage(42);
	ft.beRepaired(10);
	ft.highFivesGuys();

	std::cout << "\n\n\n ----- Diamond era -----\n";
	DiamondTrap dt;
	std::cout << " ----- Diamond 1 -----\n";
	DiamondTrap dt1("Vinni");
	std::cout << " ----- Diamond 2 -----\n";
	DiamondTrap dt2(dt1);
	dt1.attack("somebody");
	dt1.whoAmI();
	std::cout << " ----- end of Diamond era -----\n\n";
	
	return (0);
}	
