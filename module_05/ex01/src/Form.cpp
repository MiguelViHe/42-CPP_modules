/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:36:37 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/02 11:48:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExec) : 
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
	{
	if (this->_gradeSign < 1 || this->_gradeExec < 1)
		throw GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
	}

Form::Form(const Form& other) :
	_name(other._name),
	_signed(other._signed),
	_gradeSign(other._gradeSign),
	_gradeExec(other._gradeExec)
	{
		if (this->_gradeSign < 1 || this->_gradeExec < 1)
			throw GradeTooHighException();
		if (this->_gradeSign > 150 || this->_gradeExec > 150)
			throw GradeTooLowException();
		std::cout << "Form Copy constructor called" << std::endl;
	}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		std::cout << "Form Copy assignment operator called" << std::endl;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {return this->_name;}
int Form::getGradeSign() const {return this->_gradeSign;}
int Form::getGradeExec() const {return this->_gradeExec;}
bool Form::isSigned() const {return this->_signed;}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") 
	   << ", grade required to sign: " << form.getGradeSign() 
	   << ", grade required to execute: " << form.getGradeExec();
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}