/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:04:49 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/13 10:11:24 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void fun(int& i){
    i *= i;
}

void funLong(long& i){
    i = 42;
}

void funNone(const int& i){
    (void)i;
}

int main(void){
    {
    int arr[3] = {1, 2, 3};
    iter(arr, 3, fun);
    iter(arr, 3, funPrint<int>);
    std::cout << '\n';
    iter(arr, 3, funNone);
    iter(arr, 3, funPrint<int>);
    std::cout << '\n';
    //iter(arr, 3, funLong); do not compile as types of array elements and function's arg
    }
    long arr_long[3] = {1, 2, 3};
    iter(arr_long, 3, funLong);
    iter(arr_long, 3, funPrint<long>);
    
    std::string arr_str[4] = {"Thank", "you", "for", "eval"};
    iter(arr_str, 4, funPrint<std::string>);
    std::cout << "!\n";
}