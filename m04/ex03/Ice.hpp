/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:59:23 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:59:24 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice&);
		Ice& operator=(const Ice& other);
		Ice* clone() const override;
		void use(ICharacter& target) override;
};
