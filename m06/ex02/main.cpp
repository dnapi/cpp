/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:30:46 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 09:30:59 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void){
	Base* p = generate();
	std::cout << "pnt to ";
	identify(p);
	std::cout << "ref to ";
	identify(*p);
	delete p;
	return 0;
}

Base* generate(void){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 3);
	int random_number = distr(gen);
	switch (random_number){
		case 1:
			std::cout << "A generated\n";
			return (new A);
		case 2:
			std::cout << "B generated\n";
			return (new B);
	}
	std::cout << "C generated\n";
	return (new C);
	//reinterpret_cast<uintptr_t>(ptr);
}

void identify(Base* p){
A* a = dynamic_cast<A*>(p);
if (a){
	std::cout << "A\n";
	return ;
}

B* b = dynamic_cast<B*>(p);
if (b){
	std::cout << "B\n";
	return ;
}

C* c = dynamic_cast<C*>(p);
if (c){
	std::cout << "C\n";
	return ;
}
std::cout << "[ERROR] Unknown type\n";
}

void identify(Base& p){
try {
	A& a = dynamic_cast<A&>(p);
	(void)a;
	std::cout << "A\n";
	return ;
}
catch (std::bad_cast& e){};

try {
	B& b = dynamic_cast<B&>(p);
	(void)b;
	std::cout << "B\n";
	return ;
}
catch (std::bad_cast& e){};

try {
	C& c = dynamic_cast<C&>(p);
	(void)c;
	std::cout << "C\n";
	return ;
}
catch (std::bad_cast& e){}

std::cout << "[ERROR] Unknown type\n";
}