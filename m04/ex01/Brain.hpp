/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:01:33 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/04 13:01:34 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain{
	public:
		Brain();
		~Brain();
		Brain(Brain&);
		Brain& operator=(Brain& other);
	private:
		std::string	ideas[100];
};
