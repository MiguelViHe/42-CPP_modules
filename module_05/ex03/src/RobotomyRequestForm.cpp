/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:53:49 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/05 12:04:47 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>		// rand() and srand()
#include <sys/time.h>	// gettimeofday()

const int RobotomyRequestForm::_signRequired = 72;
const int RobotomyRequestForm::_execRequired = 45;

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", _signRequired, _execRequired), _target("none")
{
	std::cout << "RobotomyRequestForm empty constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", _signRequired, _execRequired), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
		std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::setTarget(const std::string& target) {
	this->_target = target;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::doAction(const Bureaucrat& executor) const
{
	struct timeval	tv;
	unsigned int	seed;

	gettimeofday(&tv, NULL);
	seed = tv.tv_sec * 1000000 + tv.tv_usec;
	std::srand(seed);
	if (std::rand() % 2)
	{
		std::cout	<< "ñiiiiiiiiiiii ñiiiiiiiiiiii... " << this->_target
					<< " has been robotomized successfully." << std::endl;
	}
	else
		std::cout << "The robotomy on " << this->_target << " has failed." << std::endl;
}