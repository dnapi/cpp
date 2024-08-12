/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:43:54 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 09:43:56 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(){}

Data::Data(int d):data(d){}

Data::~Data(){}

Data::Data(const Data& other):data(other.data){}

Data& Data::operator=(const Data& other){
	if (this == &other)
		return *this;
	data = other.data;
	return *this;
}
