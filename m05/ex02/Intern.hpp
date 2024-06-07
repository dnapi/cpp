#pragma once

class Bureaucrat{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(std::string, const int&);
		Bureaucrat& operator=(const Bureaucrat&);
	private:
};
		

std::ostream& operator<<(std::ostream&, Bureaucrat&);
