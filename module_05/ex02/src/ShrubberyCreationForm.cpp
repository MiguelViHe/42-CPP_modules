/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:17:49 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/04 17:50:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", _signRequired, _execRequired), _target("none")
{
	std::cout << "ShrubberyCreationForm empty constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", _signRequired, _execRequired), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
		std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::setTarget(const std::string& target) {
	this->_target = target;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::doAction(const Bureaucrat& executor) const 
{
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream	file;

	try
	{
		file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
		file.open(fileName.c_str(), std::ios::out | std::ios::app);
		file
		<< "          *" << std::endl
		<< "         ***" << std::endl
		<< "        *****" << std::endl
		<< "       *******" << std::endl
		<< "      *********" << std::endl
		<< "     ***********" << std::endl
		<< "    *************" << std::endl
		<< "   ***************" << std::endl
		<< "          ||       " << std::endl
		<< "          ||        " << std::endl;
		std::cout << "PLANTED BY: " << executor.getName() << std::endl;
	}
	catch(std::ofstream::failure& e)
	{
		std::cerr << "Could not create or write to file: " << fileName << std::endl;
		std::cerr << e.what() << std::endl;
	}
}