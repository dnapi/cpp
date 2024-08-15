/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:29:41 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/15 11:05:46 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include <stdexcept>


template <typename T>
typename T::const_iterator easyfind(const T& t, int i){
    typename T::const_iterator it = t.begin();
	if (typeid(*it) != typeid(int))
		throw std::exception();
    it = std::find(t.begin(), t.end(), i); 
    if (it == t.end())
        throw std::exception();
    return it;
}

template <typename T>
typename T::iterator easyfind(T& t, int i){
    typename T::iterator it = t.begin();
	if (typeid(*it) != typeid(int))
		throw std::exception();
    it = std::find(t.begin(), t.end(), i); 
    if (it == t.end())
        throw std::exception();
    return it;
}

// not there is no need to check time. 
//typename T::const_iterator it = t.begin();
	//if (typeid(*it) != typeid(int))
	//	throw std::exception();

#endif