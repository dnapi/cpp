/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:04:49 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 12:09:57 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "iter.hpp"

void fun(int& i){
    i *= i;
}

void funConst(const int& i){
    i *= i;
}

int main(void){
    std::vector<int> arr = {1, 2, 3};
    iter(arr, arr.size()),

}