/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:30:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/03 12:55:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

int	main(void)
{
	try
	{
		{
			Bureaucrat bureaucrat("Miguel", 42);
			std::cout << bureaucrat << std::endl;

			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;

			bureaucrat.decrementGrade();
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		std::cout << "-------------------" << std::endl;
		// {
		// 	Bureaucrat b2;
		// 	std::cout << b2 << std::endl;
		// 	b2.incrementGrade();
		// 	b2.decrementGrade();
		// 	b2.decrementGrade();
		// 	std::cout << b2 << std::endl;
		// }
		// std::cout << "-------------------" << std::endl;
		// {
		// 	Bureaucrat b3("Juan", 1);
		// 	std::cout << b3 << std::endl;
		// 	b3.incrementGrade();
		// 	b3.decrementGrade();
		// 	std::cout << b3 << std::endl;
		// }
		// std::cout << "-------------------" << std::endl;
		{
			Bureaucrat b4("Pedro", 0);
			std::cout << b4 << std::endl;
			b4.incrementGrade();
			std::cout << b4 << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}