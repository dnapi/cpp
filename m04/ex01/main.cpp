#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	delete j;
	delete i;

	return 0; 
}

/*
int main()
{
	std::cout << "Basic test of Animal\n";
	Animal a;
	Animal a1(a);
	Animal a2;
	a2 = a1;

	a2.makeSound();
	a2.getType();
	
	std::cout << "\n --- Test from subject --- \n";

	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound! 
	std::cout << j->getType() << " " << std::endl; 
	j->makeSound();
    meta->makeSound();
	delete meta;
	delete i;
	delete j;

	return 0;
}
*/
