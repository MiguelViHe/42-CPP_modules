/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:57:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 17:38:11 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		RPN calculator;
		try
		{
			calculator.evaluate(argv[1]);
		}
		catch (const std::exception& e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "ERROR: RPN must have only one argument" << std::endl;
	return 0;
}

/*
try:
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "7 7 * 7 -"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	./RPN "(1 + 1)"
	./RPN "9 9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * *"
	./RPN "9 0 /"
	./RPN "3 0 6 +"
	./RPN "8 0 + -"
	./RPN "42 4 +"
	./RPN "7 4 a"
	./RPN "2 +1 +"
	./RPN "2 -1 +"
 */