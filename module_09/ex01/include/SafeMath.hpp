/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SafeMath.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:32 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 16:00:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFEMATH_HPP
#define SAFEMATH_HPP

#include <exception>

class SafeMath
{
	public:
		static int safeAdd(int a, int b);
		static int safeSubtract(int a, int b);
		static int safeMultiply(int a, int b);
		static int safeDivide(int a, int b);

		class OverflowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif