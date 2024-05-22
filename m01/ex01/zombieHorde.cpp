#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	Zombie *z = new Zombie[N];
	while (N-- > 0)
		z[N].setName(name);
	return (z);
}
