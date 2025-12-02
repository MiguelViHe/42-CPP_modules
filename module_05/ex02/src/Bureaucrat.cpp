/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:42:13 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/02 11:56:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "Bureaucrat " << this->_name << " incremented to grade " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "Bureaucrat " << this->_name << " decremented to grade " << this->_grade << std::endl;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (form.isSigned())
			std::cout << this->_name << " couldn't sign " << form.getName() << " because form is already signed." << std::endl;
		else
		{
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.getName() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this); 
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t execute " << form.getName() << " because " <<  e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}