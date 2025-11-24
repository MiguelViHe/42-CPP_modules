/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:18:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/24 12:08:45 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	PmergeMe			pmergeMe(argc, argv);
	try
	{
		pmergeMe.validateArgv();
		pmergeMe.sortWithVector();
		pmergeMe.sortWithDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}