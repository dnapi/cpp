#include "MateriaSource.hpp"

MateriaSource::MateriaSource():{
	std::cout << "MateriaSource: Default constructor is called\n";
	for (int i = 0; i < 4; ++i){
		_invent[i] = nullptr;
	}
}

MateriaSource::~MateriaSource(){
	std::cout  << "MateriaSource: Destructor is called\n";
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = nullptr;
	}
}

MateriaSource::MateriaSource(std::string name): _name(name){
	std::cout << "MateriaSource: Constructor is called for name "
		<< _name << std::endl;
	for (int i = 0; i < 4; ++i){
		_invent[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other){
	std::cout << "MateriaSource: Copy constructor is called\n";
	_name = other._name;
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = other._invent[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	std::cout << "MateriaSource: operator = for name "
		<< _name << "=" << other._name
		<< " is called\n";
	_name = other._name;
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = other._invent[i]->clone();
	}
	return (*this);
}

std::string const & MateriaSource::getName() const{
	return (_name);
}

void MateriaSource::learnMateria(AMateria* m){
	std::cout << "MateriaSource: learnMateria function call by " << _name 
		<< " to take\n" << m->getType() << "\n";
	if (!m)
	{
		std::cout << "MateriaSource: Materia does note exist";
		return;
	}
	for (int i = 0; i < 4; ++i){
		if (_invent[i] != nullptr)
			continue;
		_invent[i] = m;
		return;
	}
	std::cout << "MateriaSource: no place to equip\n";
}

void MateriaSource::unequip(int idx){
	std::cout << "MateriaSource: unequip function call by " << _name << "\n";
	if (idx < 0 || idx > 3)
	{
		std::cout << "MateriaSource: position " << idx << "is out of scope\n";
		return; 
	}
	if (_invent[idx] == nullptr)
		std::cout << "MateriaSource: there is nothing to unequip.\n";
	else
		_invent[idx] = nullptr;
}

void MateriaSource::use(int idx, IMateriaSource& target){
	std::cout << "MateriaSource: use function call by " << _name 
		<< " to apply materia " << idx
		<< " on " << target.getName() << "\n";
	if (idx < 0 || idx > 3)
	{
		std::cout << "MateriaSource: position " << idx << "is out of scope\n";
		return;
	}
	if(_invent[idx])
		_invent[idx]->use(target);
	else
		std::cout << "There is no materia at position " << idx << std::endl;
}
