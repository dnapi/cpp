#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->head = 0;
	this->amount = 0;
}

void	PhoneBook::printLineSeparator(void)
{
	std::cout << std::setfill('-') << std::setw(10 * 4 + 5) << "" << std::setfill(' ') << std::endl;
}
void	PhoneBook::printAll(void)
{
	int i = 0;
	int position = 0;
	std::string	str;
	
	std::cout << std::endl << "PHONE BOOK CONTENT";
	if (this->amount == 0)
	{
		std::cout << " is empty." << std::endl;
		return ;
	}
	std::cout << std::endl;
	this->printLineSeparator();
	//std::cout << "Index, first name, last name and nickname" << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	this->printLineSeparator();
	while (i < this->amount)
	{
		position = (this->head + i) % MAX_NUM_CONTACTS;
		std::cout << "|" << std::setw(10) << i << "|";
		this->contacts[position].printEntry(&Contact::getFirstName);
		this->contacts[position].printEntry(&Contact::getLastName);
		this->contacts[position].printEntry(&Contact::getNickName);
		std::cout << std::endl;
		this->printLineSeparator();
		i++;
	}
	while (1)
	{
		std::cout << "Please, enter an index or -1 for exit: ";
		std::cin >> i;
		/*
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		*/
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong index format" << std::endl;
			continue ;
		}
		else if(i < 0)
		{
			std::cin.ignore();
			break ;
		}
		else if(i >= this->amount){
			std::cin.ignore();
			std::cout << "No data for this index" <<std::endl;
			continue ;
		}
		else
		{
			this->contacts[i].printAll();
		}
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