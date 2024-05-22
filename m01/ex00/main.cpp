#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	Zombie a("Foo");
	a.announce();
	Zombie *b = newZombie("Zuzu");
	b->announce();
	randomChump("Raro");
	delete(b);
	return (0);
}
