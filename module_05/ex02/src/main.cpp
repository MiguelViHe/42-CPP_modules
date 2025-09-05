/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:30:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/05 11:08:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	{
		std::cout << std::endl << "-- EXAMPLE 1 --" << std::endl;
		try
		{
			std::cout << std::endl << "-- CONSTRUCTORS --" << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 145);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 137);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			ShrubberyCreationForm form_1("form_1");
			std::cout << form_1 << std::endl;
			ShrubberyCreationForm form_2("form_2");
			std::cout << form_2 << std::endl;

			std::cout << std::endl << "-- TRYING TO SIGN FORMS --" << std::endl;
			low.signForm(form_1);
			signer.signForm(form_1);
			std::cout << form_1 << std::endl;

			std::cout << std::endl << "-- TRYING TO EXECUTE FORMS --" << std::endl;
			signer.executeForm(form_1);
			executor.executeForm(form_1);
			executor.executeForm(form_2);

			std::cout << std::endl << "-- SIGN AND EXECUTE FORMS --" << std::endl;
			executor.signForm(form_2);
			std::cout << form_2 << std::endl;
			executor.executeForm(form_2);
			high.executeForm(form_1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-- EXAMPLE 2 --" << std::endl;
		try
		{
			std::cout << std::endl << "-- CONSTRUCTORS --" << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 72);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 45);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			RobotomyRequestForm form_1("form_1");
			std::cout << form_1 << std::endl;
			RobotomyRequestForm form_2("form_2");
			std::cout << form_2 << std::endl;

			std::cout << std::endl << "-- TRYING TO SIGN FORMS --" << std::endl;
			low.signForm(form_1);
			signer.signForm(form_1);
			std::cout << form_1 << std::endl;

			std::cout << std::endl << "-- TRYING TO EXECUTE FORMS --" << std::endl;
			signer.executeForm(form_1);
			executor.executeForm(form_1);
			executor.executeForm(form_2);

			std::cout << std::endl << "-- SIGN AND EXECUTE FORMS --" << std::endl;
			executor.signForm(form_2);
			std::cout << form_2 << std::endl;
			executor.executeForm(form_2);
			high.executeForm(form_1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-- EXAMPLE 3 --" << std::endl;
		try
		{
			std::cout << std::endl << "-- CONSTRUCTORS --" << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 25);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 5);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			PresidentialPardonForm form_1("form_1");
			std::cout << form_1 << std::endl;
			PresidentialPardonForm form_2("form_2");
			std::cout << form_2 << std::endl;

			std::cout << std::endl << "-- TRYING TO SIGN FORMS --" << std::endl;
			low.signForm(form_1);
			signer.signForm(form_1);
			std::cout << form_1 << std::endl;

			std::cout << std::endl << "-- TRYING TO EXECUTE FORMS --" << std::endl;
			signer.executeForm(form_1);
			executor.executeForm(form_1);
			executor.executeForm(form_2);

			std::cout << std::endl << "-- SIGN AND EXECUTE FORMS --" << std::endl;
			executor.signForm(form_2);
			std::cout << form_2 << std::endl;
			executor.executeForm(form_2);
			high.executeForm(form_1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}