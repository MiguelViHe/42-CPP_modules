/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:19:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/24 15:44:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <climits>

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

//FILLING VECTOR WITH ARGV
void PmergeMe::fillVector(std::vector<int>& vec)
{
	int number;
	for (int i = 1; i < _argc; ++i)
	{
		std::istringstream iss(_argv[i]);
		iss >> number;
		vec.push_back(number);
	}
}

//MOVING PAIRS TO SMALL AND LARGE VECTORS
void PmergeMe::movePairsVector(const std::vector<int>& source, std::vector<int>& small, std::vector<int>& large)
{
	std::vector<int>::const_iterator it = source.begin();
	while (it != source.end())
	{
		int first = *it++;
		if (it != source.end())
		{
			int second = *it++;
			if (first > second)
			{
				small.push_back(second);
				large.push_back(first);
			}
			else
			{
				small.push_back(first);
				large.push_back(second);
			}
		}
		else
			small.push_back(first);
	}
}

//MERGING
void	PmergeMe::mergeVectors(std::vector<int>& small, std::vector<int>& large)
{
	//CREAR LISTA JACOB
	//IR COLONCANDO CON LOS INDICES DE JACOB
	
}

/*SORTING*/
void	PmergeMe::sortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> small;
	std::vector<int> large;

	movePairsVector(vec, small, large);
	sortVector(small);

	printVector(vec);
	printVector(small);
	printVector(large);
}

void	PmergeMe:: sortWithVector()
{
	std::vector<int> vec;
	//CONTAR TIEMPO
	fillVector(vec);
	sortVector(vec);
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

//FILLING DEQUE WITH ARGV
void PmergeMe::fillDeque(std::deque<int>& dq)
{
	int number;
	for (int i = 1; i < _argc; ++i)
	{
		std::istringstream iss(_argv[i]);
		iss >> number;
		dq.push_back(number);
	}
}

//MOVING PAIRS TO SMALL AND LARGE DEQUES
void PmergeMe::movePairsDeque(const std::deque<int>& source, std::deque<int>& small, std::deque<int>& large)
{
	std::deque<int>::const_iterator it = source.begin();
	while (it != source.end())
	{
		int first = *it++;
		if (it != source.end())
		{
			int second = *it++;
			if (first > second)
			{
				small.push_back(second);
				large.push_back(first);
			}
			else
			{
				small.push_back(first);
				large.push_back(second);
			}
		}
		else
			small.push_back(first);
	}
}

//SORTING
void	PmergeMe:: sortDeque(std::deque<int>& dq)
{
	if (dq.size() <= 1)
		return;

	std::deque<int> small;
	std::deque<int> large;

	movePairsDeque(dq, small, large);
	sortDeque(small);

	printDeque(dq);
	printDeque(small);
	printDeque(large);
}

void	PmergeMe:: sortWithDeque()
{
	std::deque<int> dq;
	//CONTAR TIEMPO
	fillDeque(dq);
	sortDeque(dq);
}

/*EXCEPTION WHAT*/
const char* PmergeMe::PmergeMeException::what() const throw()
{
	return _message.c_str();
}