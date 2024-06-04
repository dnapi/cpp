/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:35 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:36 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	public:
		virtual	~Animal();
		std::string getType() const;
		virtual void makeSound() const = 0;
	protected:
		std::string type;
		Animal();
		Animal(const Animal&);
		Animal &operator=(const Animal&);
};
