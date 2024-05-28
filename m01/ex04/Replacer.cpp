/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:55:58 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 16:34:27 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::ifstream & filestream, 
	std::string toReplace, std::string replaceWith)
	: _filestream(filestream), _toReplace(toReplace), _replaceWith(replaceWith)
{
	_fullString = readAllFromFile(_filestream);
	//std::cout << "Replacer is constructed" << std::endl;
}


std::string	Replacer::readAllFromFile(std::ifstream &filestream)
{
	std::string	str = "";
	std::string	newline;
	
	while (std::getline(filestream, newline))
	{
		str += newline;
		if (!filestream.eof())
			str += '\n';
	}
	return (str);
}

void Replacer::findAndReplace(void)
{
	size_t pos;
	pos = 0;
	while ((pos = _fullString.find(_toReplace, pos)) != std::string::npos)
	{
		_fullString.erase(pos, _toReplace.size());
		_fullString.insert(pos,_replaceWith);
		pos += _toReplace.size();
	}
}

std::string	& Replacer::getFullString(void)
{
	return	(_fullString);
}
