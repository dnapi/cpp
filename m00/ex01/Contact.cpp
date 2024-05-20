#include "Contact.hpp"

#define	EXIT_FAILURE 1
#define EXIT_SUCCESS 0

Contact::Contact()
{
	return ;
}

void	Contact::setDefault(void){
	this->firstName = "first";
	this->lastName = "last";
	this->nickName = "nick";
	this->phoneNumber = "777";
	this->secret = "secret";
}

void	Contact::printAll(void)
{
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickName << std::endl;
	std::cout << this->phoneNumber << std::endl;
	std::cout << this->secret << std::endl;
}
void	Contact::copyAll(Contact& contact)
{
	this->firstName = contact.getFirstName();
	this->lastName = contact.getLastName();
	this->nickName = contact.getNickName();
	this->phoneNumber = contact.getPhoneNumber();
	this->secret = contact.getSecret();
}

int		Contact::addContactField(std::string msg, std::string& inputLine,  Contact& contact, MemberFunction f)
{
	std::cout << msg;
	if (!std::getline(std::cin, inputLine))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (EXIT_FAILURE);
		//return (EXIT_SUCCESS);
	}
	if (std::cin.eof())
		return (EXIT_SUCCESS);
	if (inputLine.length() == 0)
	{
		std::cout << "Entry can not be empty. Please enter again." << std::endl;
		return (EXIT_FAILURE);
	}
	(contact.*f)(inputLine);
	inputLine = "";
	return (EXIT_SUCCESS);
}

void  Contact::printEntry(MemberFunVoid f){
	std::string	str;
	
	str = (this->*f)();
	if (str.length() > 10)
	{
		str.resize(9);
		str +=".";
	}
	std::cout << std::setw(10) << str << "|";
}

void	Contact::inputAll(void){
	std::string str;
	Contact		contact;

	while (this->addContactField("Enter first name:", str, contact, &Contact::setFirstName))
		;
	while (this->addContactField("Enter last name:", str, contact, &Contact::setLastName))
		;
	/*
	while (this->addContactField("Enter nickname:", str, contact, &Contact::setNickName))
		;
	while (this->addContactField("Enter phone number:", str, contact, &Contact::setPhoneNumber))
		;
	while (this->addContactField("Enter the darkest secret:", str, contact, &Contact::setSecret))
		;
	*/
	this->copyAll(contact);
}

std::string	Contact::getFirstName(void){
	return this->firstName;
}

std::string	Contact::getLastName(void){
	return this->lastName;
}

std::string	Contact::getNickName(void){
	return this->nickName;
}

std::string	Contact::getPhoneNumber(void){
	return this->phoneNumber;
}

std::string	Contact::getSecret(void){
	return this->secret;
}

void	Contact::setFirstName(std::string str){
	this->firstName = str;
}

void	Contact::setLastName(std::string str){
	this->lastName = str;
}

void	Contact::setNickName(std::string str){
	this->nickName = str;
}

void	Contact::setPhoneNumber(std::string str){
	this->phoneNumber = str;
}

void	Contact::setSecret(std::string str){
	this->secret = str;
}