/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:54:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/03 16:20:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <list>

int main(void)
{
	{
		std::cout << "Test1: Basic functionality" << std::endl;
		Span sp(5);
		try {
			sp.addNumber(6);
			sp.addNumber(23);
			sp.addNumber(7);
			sp.addNumber(78);
			sp.addNumber(42);
			sp.printSpan();
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "Test2: Exception when adding number to full Span" << std::endl;
		Span sp(3);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); //exception
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "Test3: Exception when calculating span with insufficient numbers" << std::endl;
		Span sp(2);
		try
		{
			sp.addNumber(10);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; //exception
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl; //exception
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "Test 4: 10.000 numbers" << std::endl;
		srand(static_cast<unsigned int>(time(0)));
		std::list<int> num(10000);
		for (std::list<int>::iterator i = num.begin(); i != num.end(); ++i)
			*i = rand();
		Span sp(10000);
		try
		{
			sp.addMultipleNumbers(num.begin(), num.end());
			sp.printSpan();
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught:" << e.what() << std::endl;
		}
	}
	return 0;
}