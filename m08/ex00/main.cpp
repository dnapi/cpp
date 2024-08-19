/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:31:05 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/19 13:31:49 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    const std::vector<int> v = {1, 2, 3, 4, 5};
    try {
        std::vector<int>::const_iterator it = easyfind(v, 6);  
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl; 
    }
    
    std::vector<int> w = {1, 2, 3, 4, 5};
    try {
        std::vector<int>::iterator it = easyfind(w, 3);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::vector<long> l = {1, 2, 3, 4, 5};
    try {
        std::vector<long>::iterator it = easyfind(l, 3);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
 }