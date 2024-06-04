/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:59:34 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:59:36 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(){
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	
	ICharacter* me = new Character("me");
	Character* me_c = dynamic_cast<Character*>(me);
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	ICharacter* bob = new Character("bob"); 
	me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(4, *bob);

	AMateria* floor[100] = {nullptr};
	int i = -1;
	floor[++i] = me_c->getInvent(0);
	me->unequip(0);
	me->use(0, *bob);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	me->use(0, *bob);

	delete bob; 
	delete me; 
	delete src;

	for (int i = 0; i < 100; ++i){
		delete floor[i];
		floor[i] = nullptr;
	}

	return 0;
}
