/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:57:36 by apimikov          #+#    #+#             */
/*   Updated: 2024/09/02 11:04:04 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	_LevelList[0] = "DEBUG";
	_LevelList[1] = "INFO";
	_LevelList[2] = "WARNING";
	_LevelList[3] = "ERROR";
	_LevelList[4] = "WRONG TYPE OF COMPLAIN";
	_functions[0] = &Harl::debug;
	_functions[1] = &Harl::info;
	_functions[2] = &Harl::warning;
	_functions[3] = &Harl::error;
	_functions[4] = &Harl::silence;
}

Harl::~Harl(void) {}

void Harl::printStr(std::string str) const
{
	std::cout << str << std::endl
			  << std::endl;
}

void Harl::debug(void)
{
	printStr("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!");
}

void Harl::info(void)
{
	printStr("I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
}

void Harl::warning(void)
{
	printStr("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.");
}

void Harl::error(void)
{
	printStr("This is unacceptable! I want to speak to the manager now.");
}

void Harl::silence(void){
	printStr("No comments. Allowed types of complains are DEBUG, INFO, WARNING and ERROR");
}

void Harl::complain(std::string level)
{
	int i = 0;
	while (i < 4 && level != _LevelList[i])
		i++;
	std::cout << "[ " << _LevelList[i] << " ]" << std::endl;
	(this->*_functions[i])();
}
