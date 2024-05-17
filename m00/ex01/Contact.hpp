#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact{

	public :
		Contact ();
	private :
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenum;
		std::string	secret;

};
#endif 
