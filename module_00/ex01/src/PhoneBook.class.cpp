/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:44:34 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/22 14:08:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "PhoneBook.utils.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contactCount = 0;
	this->_totalContactAdd = 0;
	std::cout << "Welcome to PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "See you soon!" << std::endl;
}

int PhoneBook::get_contactCount(void) const
{
	return (this->_contactCount);
}

void	PhoneBook::add(void)
{
	std::string str;
	Contact& contact = this->_contacts[this->_totalContactAdd % 8];

	if (this->_totalContactAdd > 7) {
	std::cout << "Warning: overwriting info about "
			  << _contacts[this->_totalContactAdd % 8].get_fname()
			  << std::endl;
	}
	str = get_non_empty_input("Enter first name: ");
	contact.set_fname(str);
	str = get_non_empty_input("Enter last name: ");
	contact.set_lname(str);
	str = get_non_empty_input("Enter nickname: ");
	contact.set_nickname(str);
	str = get_non_empty_input("Enter phone number: ");
	contact.set_phone(str);
	str = get_non_empty_input("Enter darkest secret: ");
	contact.set_secret(str);
	if (this->_contactCount < 8)
		this->_contactCount++;
	this->_totalContactAdd++;
}

void	PhoneBook::search(void) const
{
	int	index;
	int	flag;
	std::string input;

	flag = 1;
	if (this->_contactCount == 0)
		std::cout << "No names in th phonebook." << std::endl;
	else
	{
		std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << "|"
			  << std::endl;
		for (int i = 0; i < this->_contactCount; i++)
			this->_contacts[i].print_summary(i);
		while (flag)
		{
			std::cout << "Enter index to view details: ";
			if (!std::getline(std::cin, input))
			{
				std::cerr << "Input error. Aborting." << std::endl;
				exit(1);
			}
			if (input.length() != 1 || input[0] < '0' || input[0] > '7')
			{
				std::cout << "Invalid input. Please enter a digit between 0 and 7." << std::endl;
				continue;
			}
			index = input[0] - '0';
			if (index >= 0 && index < this->_contactCount)
			{
				this->_contacts[index].print_details();
				flag = 0; 
			}
			else
				std::cout << "Entry doesn't exist." << std::endl;
		}
	}
}
