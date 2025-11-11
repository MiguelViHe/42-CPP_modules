/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:17:06 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/11 17:26:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	try
	{
		if (argc == 2)
		{
			BitcoinExchange btcEx;
			btcEx.processInputFile(argv[1]);
		}
		else
			std::cerr << "Error: could not open file." << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
}