/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:42:15 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 12:10:54 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <sys/types.h>

template<typename T>
void    iter(T* arr, size_t len, void (*fun)(T&)){
    for (size_t i = 0; i < len; i++){
        fun(arr[i]);
    }
    return ;
}

template<typename T>
void    iter(const T* arr, size_t len, void (*fun)(const T&)){
    for (size_t i = 0; i < len; i++){
        fun(arr[i]);
    }
    return ;
}

#endif