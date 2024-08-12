/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:22:31 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 11:27:00 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<typename T>
void swap(T& a, T&b){
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T& min(T&a, T&b){
    if (a > b)
        return b;
    return a;
}

template<typename T>
T& max(T&a, T&b){
    if (a > b)
        return a;
    return b;
}