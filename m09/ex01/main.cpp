/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:24 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/23 12:00:53 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv){
    if (2 != argc){
        std::cerr << "Error: Please, provide one argument. \n";
    return (1);
    }
    (void)argv;
    RPN rpn;
    float result = rpn.calcExpr(argv[1]);
    if (rpn.isValid()){
        std::cout << result <<"\n";
        return 0;
    }
    rpn.print_error();
    return 1;
}