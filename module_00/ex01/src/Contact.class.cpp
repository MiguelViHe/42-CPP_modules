/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:57:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/13 17:50:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.utils.hpp"

Contact::Contact(void){}
Contact::~Contact(void){}

std::string Contact::get_fname(void) const
{
	return (this->_fname);
}

std::string Contact::get_lname(void) const
{
	return (this->_lname);
}

std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phone(void) const
{
	return (this->_phone);
}

std::string Contact::get_secret(void) const
{
	return (this->_secret);
}

void		Contact::set_fname(std::string str)
{
	this->_fname = str;
}

void		Contact::set_lname(std::string str)
{
	this->_lname = str;
}

void		Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void		Contact::set_phone(std::string str)
{
	this->_phone = str;
}
void		Contact::set_secret(std::string str)
{
	this->_secret = str;
}

void		Contact::print_summary(int index) const
{
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << truncate(this->_fname) << "|"
			  << std::setw(10) << truncate(this->_lname) << "|"
			  << std::setw(10) << truncate(this->_nickname) << "|"
			  << std::endl;
}

void		Contact::print_details(void) const
{
	std::cout << "First name: " << this->_fname << std::endl;
	std::cout << "Last name: " << this->_lname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone << std::endl;
	std::cout << "Darkest secret: " << this->_secret << std::endl;
}
