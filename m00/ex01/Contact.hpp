#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>


class Contact{

	public :
		Contact(void);
		void	setDefault(void);
		void	inputAll(void);
		void	printAll();
		void	copyAll(Contact& contact);

		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getSecret(void);
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickName(std::string str);
		void	setPhoneNumber(std::string str);
		void	setSecret(std::string str);
	private :
		typedef void	(Contact::*MemberFunction)(std::string);

		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;

		int		addContactField(std::string msg, std::string& inputLine,  Contact& contact, MemberFunction f);

};
#endif 
