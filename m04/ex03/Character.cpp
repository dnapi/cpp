#include "Character.hpp"

Character::Character(): _name("Noname"){
	std::cout << "Character: Default constructor is called\n";
	for (int i = 0; i < 4; ++i){
		_invent[i] = nullptr;
	}
}

Character::~Character(){
	std::cout  << "Character: Destructor is called\n";
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = nullptr;
	}
}

Character::Character(std::string name): _name(name){
	std::cout << "Character: Constructor is called for name " 
		<< _name << std::endl;
	for (int i = 0; i < 4; ++i){
		_invent[i] = nullptr;
	}
}

Character::Character(const Character& other){
	std::cout << "Character: Copy constructor is called\n";
	_name = other._name;
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = other._invent[i]->clone();
	}
}

Character& Character::operator=(const Character& other){
	std::cout << "Character: operator = for name " 
		<< _name << "=" << other._name 
		<< " is called\n";
	_name = other._name;
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = other._invent[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const{
	return (_name);
}

void Character::equip(AMateria* m){
	if (!m)
	{
		std::cout << "Character: Materia does note exist";
		return;
	}
	std::cout << "Character: equip function call by " << _name 
		<< " to take\n" << m->getType() << "\n";
	for (int i = 0; i < 4; ++i){
		if (_invent[i] != nullptr)
			continue;
		_invent[i] = m;
		return;
	}
	std::cout << "Character: no place to equip\n";
}

void Character::unequip(int idx){
	std::cout << "Character: unequip function call by " << _name << "\n";
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character: position " << idx << "is out of scope\n";
		return; 
	}
	if (_invent[idx] == nullptr)
		std::cout << "Character: there is nothing to unequip.\n";
	else
		_invent[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target){
	std::cout << "Character: use function call by " << _name 
		<< " to apply materia " << idx
		<< " on " << target.getName() << "\n";
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character: position " << idx << "is out of scope\n";
		return;
	}
	if(_invent[idx])
		_invent[idx]->use(target);
	else
		std::cout << "There is no materia at position " << idx << std::endl;
}

AMateria* Character::getInvent(int idx) const
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character: position " << idx << "is out of scope\n";
		return nullptr;
	}
	return _invent[idx];
}
