#include "AForm.hpp"

AForm::AForm(): _name("AbraCadabra"), _is_signed(false), _grade_to_sign(1), _grade_to_exec(1) {
	//std::cout << "AForm: Default constructor call for " << *this << "\n";
	std::cout << "AForm: Constructor call with name=" <<_name 
		<< " for grades " << _grade_to_sign << "&" << _grade_to_exec << "\n";
}

AForm::~AForm() {
	std::cout << "AForm: Destructor call for name=" << _name << "\n";
}

AForm::AForm(std::string name, int sign, int exec):
	_name(name),
	_is_signed(false),
	_grade_to_sign(sign), 
	_grade_to_exec(exec)
{
	std::cout << "AForm: Constructor call with name=" <<_name 
		<< " for grades " << sign << "&" << exec << "\n";
	checkGrade(sign);
	checkGrade(exec);
}

AForm::AForm(const AForm& other):
	_name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_exec(other._grade_to_exec)
{
	std::cout << "AForm: Copy constructor call with name=" <<_name << "\n";
}

AForm& AForm::operator=(const AForm& other){
	std::cout << "AForm: operator= call for name=" <<_name << "\n";
	if (this != &other)
		_is_signed = other._is_signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, AForm& form){
	os << " ---------  AForm --------------------\n"
		<< "    name: " << form.getName() << "\n"
		<< "    signed: " << form.getIsSigned() << "\n"
		<< "    grade to sign: " << form.getGradeToSign() << "\n"
		<< "    grade to exec: " << form.getGradeToExec() << "\n"
		<< " ---------  END --------------------\n\n";
	return os;
}

std::string AForm::getName(){
	return _name;
}

bool AForm::getIsSigned(){
	return _is_signed;
}

int AForm::getGradeToSign(){
	return _grade_to_sign;
}

int AForm::getGradeToExec(){
	return _grade_to_exec;
}

void AForm::checkGrade(int new_grade){
	if (new_grade > 150)
		throw GradeTooLowException();
	else if (new_grade < 1)
		throw GradeTooHighException();
}

void AForm::beSigned(Bureaucrat& bura){
	if (bura.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "AForm: Exception: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "AForm: Exception: Grade is too low";
}
