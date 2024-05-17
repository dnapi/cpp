#include "ClassName.hpp"

ClassName::ClassName(char p1, int p2, float p3): a1(p1), a2(p2), a3(p3)
{
	std::cout << "Call constructor" << std::endl;
	std::cout << "this->a1: " << this->a1 << std::endl;
	std::cout << "this->a2: " << this->a2 << std::endl;
	std::cout << "this->a3: " << this->a3 << std::endl;
	this->boo();
	return ;
}

ClassName::~ClassName(void)
{
	std::cout << "Call destructor" << std::endl;
	return ;
}

void ClassName::boo(void)
{
	std::cout << "Call boo function" << std::endl;
	return ;
}
