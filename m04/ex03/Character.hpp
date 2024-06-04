/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:58:36 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 12:58:37 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
  protected:
	AMateria* _invent[4];
	std::string	_name;
  public:
    Character();
    ~Character();
    Character(const Character&);
    Character(std::string name);
    Character& operator=(const Character& other);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
	AMateria* getInvent(int idx) const;
};
