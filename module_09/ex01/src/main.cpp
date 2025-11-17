/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:57:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 14:08:27 by mvidal-h         ###   ########.fr       */
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