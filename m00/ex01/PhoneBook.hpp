#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_NUM_CONTACTS 3

class PhoneBook{

	public :
		PhoneBook(void);
		void addEntry(void);
		void searchEntry(void);
		void printEntry(int i);
	private :
		Contact contacts[MAX_NUM_CONTACTS];
		int head;
		//int	const size = MAX_NUM_CONTACTS;
		int amount;	
};
#endif 
