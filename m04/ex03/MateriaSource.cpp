/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:59:40 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:59:45 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
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

MateriaSource::MateriaSource(const MateriaSource& other){
	std::cout << "MateriaSource: Copy constructor is called\n";
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = other._invent[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	std::cout << "MateriaSource: operator = is called\n";
	for (int i = 0; i < 4; ++i){
		delete _invent[i];
		_invent[i] = other._invent[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m){
	if (!m)
	{
		std::cout << "MateriaSource: Materia does note exist";
		return;
	}
	std::cout << "MateriaSource: learnMateria function called for " 
		<< m->getType() << "\n";
	for (int i = 0; i < 4; ++i){
		if (_invent[i] != nullptr)
			continue;
		_invent[i] = m;
		return;
	}
	std::cout << "MateriaSource: no place to equip\n";
	delete m;
	m = nullptr;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	std::cout << "MateriaSource: creatMateria call for type=" << type << " \n";
	for (int i = 0; i < 4; ++i){
		if (_invent[i] == nullptr)
			continue;
		if (_invent[i]->getType() == type)
			return _invent[i]->clone();
	}
	std::cout << "MateriaSource: type=" << type << " is not in the source\n";
	return nullptr;
}
