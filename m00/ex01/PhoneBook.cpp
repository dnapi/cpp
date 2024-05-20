#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->head = 0;
	this->amount = 0;
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
}

void	PhoneBook::printEntry(int i){
	std::cout << "printEntry for i=" << i << std::endl;
}