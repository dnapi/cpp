/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:42:15 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/13 09:57:27 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <sys/types.h>


template<typename T, typename F>
void iter(T *arr, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template<typename F>
void funPrint(const F& i){
    std::cout << i << ' ';
}
 
/* Alternative solution
template<typename T>
void    iter(T* arr, size_t len, void (*fun)(const T&)){
    for (size_t i = 0; i < len; i++){
        fun(arr[i]);
    }
    return ;
}

template<typename T>
void    iter(T* arr, size_t len, void (*fun)(T&)){
    for (size_t i = 0; i < len; i++){
        fun(arr[i]);
    }
    return ;
}
*/

#endif