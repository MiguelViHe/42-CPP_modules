/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:36:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/04 10:59:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string &name, const int &gradeSign, const int &gradeExec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Grade is too high";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Grade is too low";
			}
	};

private:
	const std::string	_name;
	bool 				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP