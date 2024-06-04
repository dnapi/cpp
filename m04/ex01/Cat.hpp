/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:01:40 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:01:41 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		virtual	~Cat();
		Cat &operator=(const Cat&);
		void	makeSound() const;
	private:
		Brain* brain;
};
