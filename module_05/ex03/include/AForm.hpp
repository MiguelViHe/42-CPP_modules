/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:36:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/04 17:24:28 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string &name, const int &gradeSign, const int &gradeExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Exception: Grade is too high";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Exception: Grade is too low";
			}
	};

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Exception: Form is not signed";
			}
	};

protected:
	virtual void doAction(const Bureaucrat& executor) const = 0; //polimorfismo y abstracta

private:
	const std::string	_name;
	bool 				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP