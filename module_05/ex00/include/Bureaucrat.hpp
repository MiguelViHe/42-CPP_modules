#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

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
	const std::string _name;
	int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP