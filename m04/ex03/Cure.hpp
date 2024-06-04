/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:58:44 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:58:48 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure& other);
		Cure* clone() const override;
		void use(ICharacter& target) override;
};
