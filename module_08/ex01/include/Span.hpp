/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:00:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/03 14:52:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <algorithm>

class Span {
public:
	Span();
	Span(const unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(const int &value);
	int shortestSpan() const;
	int longestSpan() const;

	void printSpan() const;
	template <typename It>
	void addMultipleNumbers(It begin, It end);

	class SpanFullException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception {
		public:
		virtual const char* what() const throw();
	};

private:
	 std::vector<int> _numbers;
	 unsigned int _maxNumbers;
};

template <typename It>
void Span::addMultipleNumbers(It begin, It end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxNumbers)
		throw Span::SpanFullException();
		_numbers.insert(_numbers.end(), begin, end);
}

#endif // SPAN_HPP