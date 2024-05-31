#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: default constractor is called\n";
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "";
	}
}

Brain::~Brain() {
	std::cout << "Brain: destructor is called\n";
}

Brain::Brain(Brain& other) {
	std::cout << "Brain: destructor is called\n";
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(Brain& other) {
	std::cout << "Brain: operator= is called\n";
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
	return (*this);
}
