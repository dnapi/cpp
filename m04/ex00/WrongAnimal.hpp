/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:00:53 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:00:55 by apimikov         ###   ########.fr       */
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
