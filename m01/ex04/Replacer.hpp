/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:54 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 16:34:38 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Replacer{
	public :
		Replacer(std::ifstream & filestream, 
			std::string toReplace,
			std::string replaceWith);
		void	findAndReplace(void);
		std::string	& getFullString(void);
		static	std::string	readAllFromFile(std::ifstream &filestream);
	private :
		std::ifstream   & _filestream;
		std::string		_fullString;
		std::string	 	_toReplace;
		std::string	 	_replaceWith;
};
