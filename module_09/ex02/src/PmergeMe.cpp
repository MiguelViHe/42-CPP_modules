/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:19:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/21 16:21:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <climits>
#include <vector>
#include <deque>

PmergeMe::PmergeMe(int argc, char** argv) : _argc(argc), _argv(argv) {}
PmergeMe::PmergeMe(const PmergeMe& other) : _argc(other._argc), _argv(other._argv) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_argc = other._argc;
		_argv = other._argv;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}


/*VALIDATION*/
void	PmergeMe::validateArgv()
{
	if (_argc < 2)
		throw PmergeMeException("Error: Not enough arguments.");
	long long number;
	for (int i = 1; i < _argc; ++i)
	{
		std::istringstream iss(_argv[i]);
		iss >> number;
		if (iss.fail() || !iss.eof())
			throw PmergeMeException("Invalid integer value: '" + std::string(_argv[i]) + "'");
		if (number < 0)
			throw PmergeMeException("Negative values are not allowed: '" + std::string(_argv[i]) + "'");
		if (number > INT_MAX)
			throw PmergeMeException("Value out of INT range (must be <= " + std::to_string(INT_MAX) + ")");
	}
}

/***************
 *   VECTOR    *
 ***************/

//PRINTING
void	printVector(const std::vector<int>& vec)
{
	std::vector<int>::const_iterator it;
	std::cout << "Vector: ";
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*SORTING*/
void	PmergeMe::sortVector()
{
	std::vector<int> vec;
	int number;
	for (int i = 1; i < _argc; ++i)
	{
		std::istringstream iss(_argv[i]);
		iss >> number;
		vec.push_back(number);
	}
	printVector(vec);
}

/***************
 *    DEQUE    *
 ***************/

//PRINTING
void	printDeque(const std::deque<int>& dq)
{
	std::deque<int>::const_iterator it;
	std::cout << "Deque: ";
	for (it = dq.begin(); it != dq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//SORTING
void	PmergeMe:: sortDeque()
{
	std::deque<int> dq;
	int number;
	for (int i = 1; i < _argc; ++i)
	{
		std::istringstream iss(_argv[i]);
		iss >> number;
		dq.push_back(number);
	}
	printDeque(dq);
}

/*EXCEPTION WHAT*/
const char* PmergeMe::PmergeMeException::what() const throw()
{
	return _message.c_str();
}