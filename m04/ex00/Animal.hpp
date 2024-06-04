/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:29 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:00:31 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal&);
		virtual	~Animal();
		Animal &operator=(const Animal&);
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};
