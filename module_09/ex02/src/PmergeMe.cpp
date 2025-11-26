/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:19:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/26 18:31:50 by mvidal-h         ###   ########.fr       */
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

bool	PmergeMe::isVectorSorted(const std::vector<int>& vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end() - 1; ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

void	PmergeMe::printVector(const std::vector<int>& vec, std::string msg, bool full)
{
	std::cout << msg;

	if (vec.empty())
	{
		std::cout << "(empty)" << std::endl;
		return;
	}
	if (full)
	{
		std::vector<int>::const_iterator it;
		for (it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		size_t limit = vec.size() < 4 ? vec.size() : 4;
		for (size_t i = 0; i < limit; ++i)
			std::cout << vec[i] << " ";
		if (limit >= 4)
			std::cout << "[...]";
		std::cout << std::endl;
	}
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
			large.push_back(first);
	}
}

//JACOBSTHAL GENERATION
std::vector<int>	PmergeMe::generateJacobsthalOrder(int n)
{
	std::vector<int> jacobsthal;
	int j0 = 0;
	int j1 = 1;

	while (j1 < n)
	{
		jacobsthal.push_back(j1);
		int jnext = j1 + (2 * j0);
		j0 = j1;
		j1 = jnext;
	}
	return jacobsthal;
}

//MERGING
void	PmergeMe::mergeVectors(std::vector<int>& large, std::vector<int>& small)
{
	std::vector<int> jacob = generateJacobsthalOrder(small.size());
	// printVector(jacob, "Jajob = ", false);
	std::vector<char> used(small.size(), 0); //Para llevar el control 
	
	for (std::vector<int>::iterator it = jacob.begin(); it != jacob.end(); ++it) {
		int index = *it;
		if (!used[index])
		{
			int value = small[index];
			std::vector<int>::iterator spos = std::lower_bound(large.begin(), large.end(), value);
			large.insert(spos, value);
			used[index] = 1; //Marcar como usado
			// std::cout << "mergeando con jacob... " << value << std::endl;
			// printVector(large, "jacob en proceso... = ", false);
		}
	}
	for (size_t i = 0; i < small.size(); ++i)// Insertar los elementos restantes
	{
		if (!used[i])
		{
			int value = small[i];
			std::vector<int>::iterator lpos = std::lower_bound(large.begin(), large.end(), value);
			large.insert(lpos, value);
			// std::cout << "mergeando restante... " << value << std::endl;
			// printVector(large, "restante en proceso... ", false);
		}
	}
}

/*SORTING*/
void	PmergeMe::sortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> small;
	std::vector<int> large;

	movePairsVector(vec, small, large);
	// printVector(vec, "Original esta vuelta = ", false);
	// printVector(large, "large = ", false);
	// printVector(small, "small = ", false);
	sortVector(large);
	// printVector(large, "Salida de recursividad = ", false);
	// printVector(small, "a mergear: ", false);
	mergeVectors(large, small);
	vec = large;
	// printVector(vec, "Una vez mergeado = ", false);
}

double	PmergeMe:: sortWithVector()
{
	std::vector<int> vec;
	fillVector(vec);
	printVector(vec, "Before: ", false);
	clock_t	start_time = clock();
	sortVector(vec);
	double	end_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC * 1000;
	printVector(vec, "After: ", false);
	if (!isVectorSorted(vec))
		throw PmergeMeException("Vector is not sorted correctly.");
	return end_time;
}

/***************
 *    DEQUE    *
 ***************/

//PRINTING
void	PmergeMe::printDeque(const std::deque<int>& dq)
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

double	PmergeMe:: sortWithDeque()
{
	std::deque<int> dq;
	//CONTAR TIEMPO
	fillDeque(dq);
	sortDeque(dq);
	return (0.0);
}

/*EXCEPTION WHAT*/
const char* PmergeMe::PmergeMeException::what() const throw()
{
	return _message.c_str();
}