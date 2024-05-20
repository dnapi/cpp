#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define MAX_NUM_CONTACTS 3

class PhoneBook{

	public :
		PhoneBook(void);
		void printAll(void);
		void addEntry(void);
		void searchEntry(void);
		void printEntry(int i);
	private :
		//typedef void	(Contact::*MemberFunction)(std::string);
		Contact contacts[MAX_NUM_CONTACTS];
		int head;
		//int	const size = MAX_NUM_CONTACTS;
		int amount;	

		void printLineSeparator(void);
};
#endif 
