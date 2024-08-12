/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:44:04 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 09:44:10 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void){
	Data d(42);

	uintptr_t ptr = Serializer::serialize(&d);
	Data* d_ptr =Serializer::deserialize(ptr);
	std::cout << "data=" << d_ptr->data << "\n";
	return (0);
}