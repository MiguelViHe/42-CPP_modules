/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SafeMath.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 16:59:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SafeMath.hpp"
#include <climits>

int	SafeMath::safeAdd(int a, int b)
{
	if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
		throw OverflowException();
	return (a + b);
}

int	SafeMath::safeSubtract(int a, int b)
{
	if ( (b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b) )
		throw OverflowException();
	return (a - b);
}

int	SafeMath::safeMultiply(int a, int b)
{
	if (a != 0 && b != 0) {
		if (a > 0 && b > 0 && a > INT_MAX / b) throw OverflowException();
		if (a < 0 && b < 0 && a < INT_MAX / b) throw OverflowException();
		if (a > 0 && b < 0 && b < INT_MIN / a) throw OverflowException();
		if (a < 0 && b > 0 && a < INT_MIN / b) throw OverflowException();
	}
	return a * b;
}

int	SafeMath::safeDivide(int a, int b)
{
	if (b == 0)
		throw DivisionByZeroException();
	return a / b;
}

//Exceptions
const char* SafeMath::OverflowException::what() const throw()
{
	return "Overflow Exception: Arithmetic operation resulted in an overflow.";
}

const char* SafeMath::DivisionByZeroException::what() const throw()
{
	return "Division By Zero Exception: Attempted division by zero.";
}