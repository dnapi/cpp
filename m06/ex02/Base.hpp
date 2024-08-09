#ifndef BASE_HPP
# define BASE_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base{
	Base();
	virtual ~Base();
	Base(const Base&);
	Base& operator=(const Base&);
	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif