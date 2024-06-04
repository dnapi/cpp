#include "Ice.hpp"

Ice::Ice(){
	std::cout << "Ice: Default constructor is called\n";
	type = "ice";
}

Ice::~Ice(){
	std::cout  << "Ice: Destructor is called\n";
}

Ice::Ice(const Ice& other): AMateria(){
	(void)other;
	type = "ice";
	std::cout << "Ice: Copy constructor for type " 
		<< type << " is called\n";
}

Ice& Ice::operator=(const Ice& other){
	std::cout << "Ice: operator = for type " << type << " is called\n";
	(void)other;
	return (*this);
}

Ice* Ice::clone() const{
	std::cout << "Ice: clone for type " << type << " is called\n";
	Ice* i = new Ice();
	return i;
}

// Cure: "* heals <name>’s wounds *"
void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " 
		<< target.getName() << " *\n";
}

/*
std::string const & Ice::getType() const {
	std::cout << "Ice: getter for type " << type << " is called\n";
	return (type);
}
*/

/*
Ice::Ice(std::string const& type_arg): type(type_arg){
	std::cout << "Ice: constructor from string for type " 
		<< type << " is called\n";
}
*/
