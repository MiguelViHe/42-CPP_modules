/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:40:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 13:01:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void	evaluate(const std::string& expression);

		class NoValidElementException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class StackUnderFlowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoUniqueResultException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::stack<int> _stack;

		bool	isOperator(std::string& token) const;
		bool	isDigit(std::string& token) const;
		int		popSafe();
		void	applyOperator(std::string& token);
		void	applyDigit(std::string& token);
		void	processToken(std::string& token);
		void	checkResult();
};

#endif