/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:56:17 by apimikov          #+#    #+#             */
/*   Updated: 2024/05/24 12:30:01 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>


class Contact{

	public :
		Contact(void);
		typedef std::string	(Contact::*MemberFunVoid)(void);
		void	setDefault(void);
		void	inputAll(void);
		void	printAll();
		void	copyAll(Contact& contact);
		void	printEntry(MemberFunVoid f);

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
