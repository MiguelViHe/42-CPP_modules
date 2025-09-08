/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:12:00 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/08 11:36:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& formTarget);

	class UnknownFormException : public std::exception
	{
		public:
			const char * what() const throw() {
				return "Unknown form type";
			}
	};

private:
	static AForm* createShrubberyCreationForm(const std::string& target); //con static pertenecen a la clase y no a la instancia
	static AForm* createRobotomyRequestForm(const std::string& target); //se pueden usar sin crear una instancia de la clase
	static AForm* createPresidentialPardonForm(const std::string& target); //tal como: Intern::createShrubberyCreationForm("target") Es como una funcion externa pero más encapsulada
};
#endif // INTERN_HPP