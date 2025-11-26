/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:18:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/26 18:24:18 by mvidal-h         ###   ########.fr       */
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
		double timeVector = pmergeMe.sortWithVector();
		// double timeDeque = pmergeMe.sortWithDeque();
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeVector << " us" << std::endl;
		// std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << timeDeque << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}