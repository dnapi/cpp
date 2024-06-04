/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:59:48 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:59:51 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria* _invent[4];
  	public:
	    MateriaSource();
	    ~MateriaSource();
    	MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
