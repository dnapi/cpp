#include "Base.hpp"

Base();
	virtual ~Base();
	Base(const Base&);
	Base& operator=(const Base&);
	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif