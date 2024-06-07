/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:15:33 by apimikov          #+#    #+#             */
/*   Updated: 2024/06/07 15:16:08 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
     if (1){
	Form f("boss", 42, 42);
	std::cout << f << std::endl;
	Form ff(f);
	Form cc;
	cc = ff;
	std::cout << "\n";
	try {
		Form buro1("***High***", 0, 30);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		Form buro1("***Low***", 151, 30);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		Form buro1("***High***", 30, 0);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		Form buro1("***Low***", 30, 151);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
     }
     if (1){
	Bureaucrat boss("Boss", 42);
	Bureaucrat big_boss("BIG Boss", 1);
	Form	certif("Certif", 1, 50);
	Form	card("Card", 100, 100);
	std::cout << "*****  Buracratic machine  ******\n";
	boss.signForm(certif);
	big_boss.signForm(certif);
	boss.signForm(certif);
	boss.signForm(card);
	big_boss.signForm(card);
	std::cout << "*****  STOP machine  ******\n";
	
     }
	return 0;
}
