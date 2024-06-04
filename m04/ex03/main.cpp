#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

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

	Character c;
	Character c1("Cat");
	c.equip(p);
	c.equip(p1);
	c.equip(p2);
	c.equip(p3);
	c.equip(p4);
	c.unequip(2);
	c.equip(p2);
	c.use(2,c1);
	c.use(3,c1);
	c.use(0,c1);
	c.use(8,c1);
/*	delete p;
	delete p1;
	delete p2;
	delete p3;*/
	delete p4;
/*	p = nullptr;
	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;*/
	p4 = nullptr;
	return 0;
}
