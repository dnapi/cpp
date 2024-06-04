#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(){
	AMateria* m;
	(void)m;
	Ice i;
	m = &i;
	AMateria* p = m->clone();
	AMateria* p1 = m->clone();
	AMateria* p2 = m->clone();
	AMateria* p3 = m->clone();
	AMateria* p4 = m->clone();
//	std::cout << "ice=" << p->getType()  << std::endl;

	AMateria* tmp;
	MateriaSource source;
	source.learnMateria(m);
	tmp = source.createMateria("ice");
	Character c;
	c.equip(tmp);
	Character c1("Cat");
	c.use(0,c1);
	std::cout << "--- end of test ---\n";
	delete p;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
/*	p = nullptr;
	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;*/
	p4 = nullptr;
	return 0;
}
