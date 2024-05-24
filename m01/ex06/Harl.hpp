/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:09:20 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 16:09:21 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Harl{
	public:
		Harl(void);
		~Harl(void);
		void	printStr(std::string str) const;
		void	complain(std::string level);
		void	complainAll(int startLevel);
		int		levelToInt(std::string level);
	private :
		void	(Harl::*_functions[5])(void);
		std::string _LevelList[5];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	silence(void);
};
