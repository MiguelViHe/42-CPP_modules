/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:46:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 17:02:00 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "SafeMath.hpp"
#include <iostream>
#include <sstream>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}
RPN::~RPN() {}

void	RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string	token;
	while (std::getline(iss, token, ' '))
	{
		if (token.size() != 1)
			throw NoValidElementException();
		if (!isOperator(token) && !isDigit(token))
			throw NoValidElementException();
		processToken(token);
	}
	checkResult();
}

bool	RPN::isOperator(std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool	RPN::isDigit(std::string& token) const
{
	return (std::isdigit(static_cast<unsigned char>(*token.begin())));
}

int		RPN::popSafe()
{
	if (_stack.empty())
		throw StackUnderFlowException();
	int number = _stack.top();
	_stack.pop();
	return number;
}

void	RPN::applyOperator(std::string& token)
{
	int	b = popSafe();
	int	a = popSafe();
	int	result;
	if (token == "+") {result = SafeMath::safeAdd(a, b);}
	else if (token == "-") {result = SafeMath::safeSubtract(a, b);}
	else if (token == "*") {result = SafeMath::safeMultiply(a, b);}
	else if (token == "/") {result = SafeMath::safeDivide(a, b);}
	else {throw NoValidElementException();}
	_stack.push(result);
}

void	RPN::applyDigit(std::string& token)
{
	std::istringstream iss(token);
	int number;
	iss >> number;
	if (iss.fail() || !iss.eof())
		throw NoValidElementException();
	_stack.push(number);
}

void	RPN::processToken(std::string& token)
{
	if (isOperator(token))
		applyOperator(token);
	else
		applyDigit(token);
}

void	RPN::checkResult()
{
	if (_stack.size() == 1)
	{
		int result = _stack.top();
		std::cout << result << std::endl;
	}
	else
		throw NoUniqueResultException();
}

// Exception messages

const char* RPN::NoValidElementException::what() const throw()
{
	return "No valid element in input string";
}

const char* RPN::StackUnderFlowException::what() const throw()
{
	return "Not enough elements in stack";
}

const char* RPN::NoUniqueResultException::what() const throw()
{
	return "Too much elements in stack after process input";
}