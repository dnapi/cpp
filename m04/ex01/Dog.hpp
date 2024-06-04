/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:01:46 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:01:47 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		virtual	~Dog();
		Dog &operator=(const Dog&);
		void	makeSound() const;
    private:
        Brain* brain;
};
