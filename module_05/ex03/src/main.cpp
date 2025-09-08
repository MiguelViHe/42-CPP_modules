/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:30:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/08 12:04:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	{
		std::cout << std::endl << "-- EXAMPLE 1 --" << std::endl;
		try
		{
			Intern someRandomIntern;
			std::cout << std::endl << "-- CONSTRUCTORS --" << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 145);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 137);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			AForm* ptrForm_1 = someRandomIntern.makeForm("shrubbery creation", "form_1");
			std::cout << *ptrForm_1 << std::endl;
			AForm* ptrForm_2 = someRandomIntern.makeForm("shrubbery creation", "form_2");
			std::cout << *ptrForm_2 << std::endl;

			std::cout << std::endl << "-- TRYING TO SIGN FORMS --" << std::endl;
			low.signForm(*ptrForm_1);
			signer.signForm(*ptrForm_1);
			std::cout << *ptrForm_1 << std::endl;

			std::cout << std::endl << "-- TRYING TO EXECUTE FORMS --" << std::endl;
			signer.executeForm(*ptrForm_1);
			executor.executeForm(*ptrForm_1);
			executor.executeForm(*ptrForm_2);

			std::cout << std::endl << "-- SIGN AND EXECUTE FORMS --" << std::endl;
			executor.signForm(*ptrForm_2);
			std::cout << *ptrForm_2 << std::endl;
			executor.executeForm(*ptrForm_2);
			high.executeForm(*ptrForm_1);
			delete ptrForm_1;
			delete ptrForm_2;
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
			Intern someRandomIntern;
			std::cout << std::endl << "-- CONSTRUCTORS --" << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 72);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 45);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			AForm* ptrForm_1 = someRandomIntern.makeForm("robotomy request", "form_1");
			std::cout << *ptrForm_1 << std::endl;
			AForm* ptrForm_2 = someRandomIntern.makeForm("robotomy request", "form_2");
			std::cout << *ptrForm_2 << std::endl;

			std::cout << std::endl << "-- TRYING TO SIGN FORMS --" << std::endl;
			low.signForm(*ptrForm_1);
			signer.signForm(*ptrForm_1);
			std::cout << *ptrForm_1 << std::endl;

			std::cout << std::endl << "-- TRYING TO EXECUTE FORMS --" << std::endl;
			signer.executeForm(*ptrForm_1);
			executor.executeForm(*ptrForm_1);
			executor.executeForm(*ptrForm_2);

			std::cout << std::endl << "-- SIGN AND EXECUTE FORMS --" << std::endl;
			executor.signForm(*ptrForm_2);
			std::cout << *ptrForm_2 << std::endl;
			executor.executeForm(*ptrForm_2);
			high.executeForm(*ptrForm_1);
			delete ptrForm_1;
			delete ptrForm_2;
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
			Intern someRandomIntern;
			std::cout << std::endl << "-- CONSTRUCTORS --" << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 25);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 5);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			AForm* ptrForm_1 = someRandomIntern.makeForm("presidential pardon", "form_1");
			std::cout << *ptrForm_1 << std::endl;
			AForm* ptrForm_2 = someRandomIntern.makeForm("presidential pardon", "form_2");
			std::cout << *ptrForm_2 << std::endl;

			std::cout << std::endl << "-- TRYING TO SIGN FORMS --" << std::endl;
			low.signForm(*ptrForm_1);
			signer.signForm(*ptrForm_1);
			std::cout << *ptrForm_1 << std::endl;

			std::cout << std::endl << "-- TRYING TO EXECUTE FORMS --" << std::endl;
			signer.executeForm(*ptrForm_1);
			executor.executeForm(*ptrForm_1);
			executor.executeForm(*ptrForm_2);
			
			std::cout << std::endl << "-- SIGN AND EXECUTE FORMS --" << std::endl;
			executor.signForm(*ptrForm_2);
			std::cout << *ptrForm_2 << std::endl;
			executor.executeForm(*ptrForm_2);
			high.executeForm(*ptrForm_1);
			delete ptrForm_1;
			delete ptrForm_2;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-- EXAMPLE 4 --" << std::endl;
		try
		{
			Intern someRandomIntern;
			std::cout << std::endl << "-- UNKNOWN FORM --" << std::endl;
			AForm* ptrForm_1 = someRandomIntern.makeForm("unknown form", "form_1");
			std::cout << *ptrForm_1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}