/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:36:37 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/09 13:20:54 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeSign, const int &gradeExec) : 
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
	{
	if (this->_gradeSign < 1 || this->_gradeExec < 1)
		throw GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
	}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_signed(other._signed),
	_gradeSign(other._gradeSign),
	_gradeExec(other._gradeExec)
	{
		std::cout << "AForm Copy constructor called" << std::endl;
	}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		std::cout << "AForm Copy assignment operator called" << std::endl;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const {return this->_name;}
int AForm::getGradeSign() const {return this->_gradeSign;}
int AForm::getGradeExec() const {return this->_gradeExec;}
bool AForm::isSigned() const {return this->_signed;}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	this->doAction(executor);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") 
	   << ", grade required to sign: " << form.getGradeSign() 
	   << ", grade required to execute: " << form.getGradeExec();
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Exception: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Exception: Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Exception: Form is not signed";
}