/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:26:42 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/20 10:35:41 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int argc, char** argv){
    if (argc != 2){
        std::cout << "Please provide one file name as an argument\n";
        return (1);
    }
    /*
    std::string filename = argv[1];
    size_t position_ext = std::string(filename).rfind('.');
    std::string file_extension = filename.substr(position_ext);
    if (file_extension != ".csv"){
        std::cout << "Please provide one file name with extension .csv\n";
        return (1);
    }
    */
    
    return(0);
}