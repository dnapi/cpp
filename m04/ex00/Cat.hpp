/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:35 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:00:37 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		virtual	~Cat();
		Cat &operator=(const Cat&);
		void	makeSound() const;
};
