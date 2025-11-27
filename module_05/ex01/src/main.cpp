/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:30:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/27 17:49:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		{
			Bureaucrat bureaucrat("Miguel", 31);
			std::cout << bureaucrat << std::endl;
			Form formA("FormA", 50, 20);
			Form formB("FormB", 30, 10);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;
			bureaucrat.signForm(formA);
			bureaucrat.signForm(formB);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;
			bureaucrat.incrementGrade();
			bureaucrat.signForm(formB);
			std::cout << formB << std::endl;
			bureaucrat.signForm(formB);
		}
		std::cout << "-------------------" << std::endl;
		{
			Bureaucrat b3("Juan", 1);
			std::cout << b3 << std::endl;
			Form formD("FormD", 1, 1);
			Form formE(formD);
			std::cout << formD << std::endl;
			std::cout << formE << std::endl;
			b3.signForm(formD);
			b3.signForm(formE);
			std::cout << formD << std::endl;
			std::cout << formE << std::endl;
		}
		std::cout << "-------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}