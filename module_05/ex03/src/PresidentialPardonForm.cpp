/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:38 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/05 12:06:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

const int PresidentialPardonForm::_signRequired = 25;
const int PresidentialPardonForm::_execRequired = 5;

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", _signRequired, _execRequired), _target("none")
{
	std::cout << "PresidentialPardonForm empty constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", _signRequired, _execRequired), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
		std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::setTarget(const std::string& target) {
	this->_target = target;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::doAction(const Bureaucrat& executor) const 
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	(void)executor;
}