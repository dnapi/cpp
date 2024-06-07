#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
     if (1){
	ShrubberyCreationForm f("home");
	std::cout << f << std::endl;
	ShrubberyCreationForm ff(f);
	ShrubberyCreationForm cc;
	cc = ff;
	std::cout << "\n";
	}
/*
     if (0){
	try {
		AForm buro1("***High***", 0, 30);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		AForm buro1("***Low***", 151, 30);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		AForm buro1("***High***", 30, 0);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		AForm buro1("***Low***", 30, 151);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	Bureaucrat boss("Boss", 42);
	Bureaucrat big_boss("BIG Boss", 1);
	AForm	certif("Certif", 1, 50);
	AForm	card("Card", 100, 100);
	std::cout << "*****  Buracratic machine  ******\n";
	boss.signForm(certif);
	big_boss.signForm(certif);
	boss.signForm(certif);
	boss.signForm(card);
	big_boss.signForm(card);
	std::cout << "*****  STOP machine  ******\n";
	
     }
*/
	return 0;
}
