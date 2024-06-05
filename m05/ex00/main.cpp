#include "Bureaucrat.hpp"

int main(){
	Bureaucrat b;
	std::cout << b << std::endl;
	Bureaucrat bb(b);
	Bureaucrat cc;
	cc = bb;
	try {
		Bureaucrat buro1("***High***", 0);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		Bureaucrat buro1("***Low***", 151);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		Bureaucrat buro1("*** decrement ***", 150);
		buro1.decrement();
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try {
		Bureaucrat buro1("*** increment ***", 1);
		buro1.increment();
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	{
		std::cout << "=====EXTRA TESTS ================================" << std::endl;
		Bureaucrat low("low", 150);
		low.increment();
		try
		{
			low.decrement();
			low.decrement();
		}
		catch(std::exception& e)
		{
			std::cout << "cannot Decrement grade" << std::endl;
		}
		Bureaucrat high("high", 1);
		high.decrement();
		try
		{
			high.increment();
			high.increment();
		}
		catch(std::exception& e)
		{
			std::cout << "cannot Increment grade" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		try
		{
			Bureaucrat low("low", 151);
		}
		catch(std::exception& e)
		{
			std::cout << "init grade too low" << std::endl;
		}
		try
		{
			Bureaucrat high("high", 0);
		}
		catch(std::exception& e)
		{
			std::cout << "init grade too high" << std::endl;
		}
	}
	{
		std::cout << "==================================================" << std::endl;
		Bureaucrat Bob("Bob", 42);
		Bob.increment();
		Bureaucrat Bob2(Bob);
		Bob2.decrement();
		Bob2.decrement();
		Bob2.decrement();
		Bob2.decrement();
		Bureaucrat Will("Will", 69);
		Will.increment();
		Will.increment();
		Will.increment();
		Will.increment();
		Will.increment();
		Will.increment();
		Will.increment();
		Will.increment();
		Will = Bob2;
		std::cout << Will << std::endl;
	}
	std::cout << "==================================================" << std::endl;

	return 0;
}
