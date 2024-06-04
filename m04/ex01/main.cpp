/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:06 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:07 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	const Animal* i = new Cat();
	const Animal* j = new Dog(); 
	const Animal* k = new Dog(); 
	const Animal* l = new Cat();

	const Animal* zoo[4] =  {i, j, k, l};
	for (const Animal* a : zoo) {
		a->makeSound();
	}

	Dog basic;
	basic.makeSound();
	{
		Dog tmp;
		tmp = basic;
		tmp.makeSound();
	}

	//delete i;
	for (const Animal* a : zoo) {
		delete a;
	}
	return 0; 
}