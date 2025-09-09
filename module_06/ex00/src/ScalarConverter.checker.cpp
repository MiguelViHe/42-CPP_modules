/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.checker.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:30:55 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/09 13:52:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isInt(const std::string& input)
{
	if (input.empty())
		return (false);
	size_t	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (int j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloatSpecial(const std::string& input)
{
	return (input == "-inff" || input == "+inff" || input == "nanf");
}

bool ScalarConverter::isFloat(const std::string& input)
{
	if (input.empty())
		return (false);
	if (isFloatSpecial(input))
		return (true);
	size_t	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	bool hasDigitsBeforeDot = false;
	while (i < input.length() && isdigit(input[i]))
	{
		i++;
		hasDigitsBeforeDot = true;
	}
	if (i >= input.length() || input[i] != '.')
		return (false);
	i++;
	bool hasDigitsAfterDot = false;
	while (i < input.length() && isdigit(input[i]))
	{
		i++;
		hasDigitsAfterDot = true;
	}
	if (i >= input.length() || (input[i] != 'f' && input[i] != 'F'))
		return (false);
	i++;
	if ((!hasDigitsBeforeDot || !hasDigitsAfterDot))
		return (false);
	return (i == input.length());
}

bool ScalarConverter::isDoubleSpecial(const std::string& input)
{
	return (input == "-inf" || input == "+inf" || input == "nan");
}

bool ScalarConverter::isDouble(const std::string& input)
{
	if (input.empty())
		return (false);
	if (isDoubleSpecial(input))
		return (true);
	size_t	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	
	bool hasDigitsBeforeDot = false;
	while (i < input.length() && isdigit(input[i]))
	{
		i++;
		hasDigitsBeforeDot = true;
	}
	if (i >= input.length() || input[i] != '.')
		return (false);
	i++;
	bool hasDigitsAfterDot = false;
	while (i < input.length() && isdigit(input[i]))
	{
		i++;
		hasDigitsAfterDot = true;
	}
	if (!hasDigitsBeforeDot || !hasDigitsAfterDot)
		return (false);
	return (i == input.length());
}

bool ScalarConverter::isChar(const std::string& input)
{
	if (input.empty())
		return (false);
	if (input.length() != 1)
		return (false);
	return (true);
}

ScalarConverter::type ScalarConverter::parse(const std::string& literal)
{
	if (isChar(literal))
		return (CHAR);
	else if (isInt(literal))
		return (INT);
	else if (isFloat(literal))
		return (FLOAT);
	else if (isDouble(literal))
		return (DOUBLE);
	else
		return (ERROR);
}