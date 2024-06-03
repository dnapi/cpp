#include "Character.hpp"

Character::Character(){
	std::cout << "Character: Default constructor is called\n";
}

Character::~Character(){
	std::cout  << "Character: Destructor is called\n";
}

Character::Character(std::string name) _name(name){
	std::cout << "Character: Constructor is called for name " 
		<< _name << std::endl;
}

Character::Character(const Character& other){
	(void)other;
	std::cout << "Character: Copy constructor is called\n";
}

Character& Character::operator=(const Character& other){
	std::cout << "Character: operator = for type " << type << " is called\n";
	(void)other;
	return (*this);
}

std::string const & Character::getName() const{
	return (_name)
}
