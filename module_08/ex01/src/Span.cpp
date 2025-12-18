/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:00:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/18 16:47:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>

Span::Span() : _maxNumbers(0)
{
	std::cout << "Span empty constructor called" << std::endl;
}

Span::Span(const unsigned int N) : _maxNumbers(N)
{
	_numbers.reserve(N);
	std::cout << "Span parameterized constructor called" << std::endl;
}

//_numbers(other._numbers) ya se encarga de reservar memoria y copiar los valores
// del vector other._numbers al nuevo objeto que se está creando. AMBOS tienen
// espacios de memoria diferentes. Pero solo porque es un contenedor ya definido
// que tiene sus propio constructor de copia ya definido para hacer el deep_copy.
//Por ejemplo en un array creado por nosotros mismo (new()) tendriamos que hacer
// un bucle para copiar elemento a elemento.
Span::Span(const Span& other) : _maxNumbers(other._maxNumbers), _numbers(other._numbers)
{
	std::cout << "Span copy constructor called" << std::endl;
}

//std::vector en _numbers = other._numbers; ya implementa internamente su propio copy constructor
// y operator= profundos. Por lo tanto, se encarga de la asignación
// liberando memoria previa y copiando los valores si el vector other
// es mayor que el actual. SI el actual es mayor o igual que other,
// copia directamente. AMBOS se quedan con espacios de memoria diferentes.
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxNumbers = other._maxNumbers;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(const int &value)
{
	if (_numbers.size() >= _maxNumbers)
		throw Span::SpanFullException();
	_numbers.push_back(value);
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw Span::NotEnoughNumbersException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minDiff = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
		minDiff = std::min(minDiff, sorted[i] - sorted [i - 1]);
	return (minDiff);
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw Span::NotEnoughNumbersException();
	std::vector<int>::const_iterator itMin = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator itMax = std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<int>(*itMax) - static_cast<int>(*itMin));
}

void Span::printSpan () const
{
	std::cout << "Span content:" << std::endl;
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

const char* Span::SpanFullException::what() const throw()
{
	return ("Span is full. Cannot add more numbers.");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in Span.");
}

