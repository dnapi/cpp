#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
    
	Bureaucrat boss("boss", 1);
	Bureaucrat junior("junior", 150);
	ShrubberyCreationForm form_s("home");
	RobotomyRequestForm form_r("cluster");
	PresidentialPardonForm form_p("42 school");
	std::cout << " ------   Test 0 Shrubbery basic ------- \n";
	std::cout << form_s << std::endl;
	ShrubberyCreationForm ff(form_s);
	ShrubberyCreationForm cc;
	cc = ff;
	std::cout << "signed=" << cc.getIsSigned() << "\n";
	
	std::cout << "\n ------   Test 1 Shrubbery sign and exec ------- \n";
	junior.executeForm(form_s);
	junior.signForm(form_s);
	boss.signForm(form_s);
	junior.executeForm(form_s);
	boss.executeForm(form_s);

	std::cout << "\n ------   Test 2 Robotomy sign and exec ------- \n";
	junior.executeForm(form_r);
	junior.signForm(form_r);
	boss.signForm(form_r);
	junior.executeForm(form_r);
	boss.executeForm(form_r);

	std::cout << "\n ------   Test 3 Presidential sign and exec ------- \n";
	junior.executeForm(form_p);
	junior.signForm(form_p);
	boss.signForm(form_p);
	junior.executeForm(form_p);
	boss.executeForm(form_p);
	
	std::cout << "\n\n ------   END ------- \n" << std::endl;
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
