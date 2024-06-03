#include "Character.hpp"

Character::Character(){
	std::cout << "Character: Default constructor is called\n";
	for (int i = 0; i < 4; ++i){
		_invent[i] = nullptr;
	}
}

Character::~Character(){
	std::cout  << "Character: Destructor is called\n";
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
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
	(void)other;
	std::cout << "Character: Copy constructor is called\n";
	_name = other._name;
	for (int i = 0; i < 4; ++i){
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
	for (int i = 0; i < 4; ++i){
		if (_invent[i] != nullptr)
			continue;
		_invent[i] = m;
		break;
	}
}
void Character::unequip(int idx){
}
void Character::use(int idx, ICharacter& target){
}