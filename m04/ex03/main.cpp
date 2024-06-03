#include "AMateria.hpp"
#include "Ice.hpp"

int main(){
	AMateria* m;
	(void)m;
	Ice i;
	m = &i;
	AMateria* p = m->clone();
	std::cout << "ice="p->getType()  << std::endl;

	delete p;
	return 0;
}
