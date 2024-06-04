/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:03:07 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:03:09 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		virtual	~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal&);
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string type;
};
