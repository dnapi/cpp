#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->head = 0;
	this->amount = 0;
}

void	printLineSeparator(void)
{
	std::cout << std::setw(10 * 4 + 5) << 
		"------------------------------------------------------------" << std::endl;
}
void	PhoneBook::printAll(void)
{
	int i = 0;
	int position = 0;
	
	std::cout << "PHONE BOOK CONTENT" << std::endl;
	this->printLineSeparator();
	std::cout << "Index, first name, last name and nickname" << std::endl;
	std::cout << std::setw(10) << "Index" << "|" << std::endl;
	std::cout << std::setw(10) << "First name" << "|" << std::endl;
	std::cout << std::setw(10) << "Last name" << "|" << std::endl;
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	this->printLineSeparator();
	while (i < this->amount)
	{
		position = (this->head + i) % MAX_NUM_CONTACTS;
		std::cout << " --- Index i=" << i << "Position =" << position << std::endl;
		std::cout << "|" << std::setw(10) << i << "|" << std::endl;
		std::cout << std::setw(10) << this->contacts[position].getFirstName() << "|" << std::endl;
		this->printLineSeparator();
		//this->contacts[position].printAll();
		i++;
	}
	//std::cout << " ----------- " << std::endl;
}

void	PhoneBook::addEntry(void){
	std::cout << "Starting addjing entry" << std::endl;

	int i = 0;
	Contact contact;

	//contact.setDefault();
	contact.inputAll();

	if (this->amount < MAX_NUM_CONTACTS)
	{
		i = this->amount;
		this->amount++;
	}
	else if (this->amount == MAX_NUM_CONTACTS)
	{
		i = this->head;
		this->head = (this->head + 1) % MAX_NUM_CONTACTS;
	}
	this->contacts[i] = contact;
	return ;
}

void	PhoneBook::searchEntry(void){
	std::cout << "Starting searching entry" << std::endl;
	this->printAll();
}

void	PhoneBook::printEntry(int i){
	std::cout << "printEntry for i=" << i << std::endl;
}