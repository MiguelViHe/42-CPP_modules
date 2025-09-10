/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.printer.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:12:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/10 16:26:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

#include <climits> // INT_MIN, INT_MAX
#include <cfloat> // FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
// #include <cmath> // std::isnan(),  std::isinf()
#include <sstream> // stringstream
#include <iomanip>  // std::fixed and std::setprecision
// #include <cstdlib> // strtod, strtol

void ScalarConverter::printChar(const std::string& input)
{
	char c = input[0];
	if (!isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printOutOfRange(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printInt(const std::string& input)
{
	long nbr;

	std::stringstream ss(input);
	ss >> nbr;

	if (nbr < INT_MIN || nbr > INT_MAX)
	{
		printOutOfRange();
		return ;
	}
	if (nbr < 0 || nbr > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(nbr)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nbr) << std::endl;
}

void ScalarConverter::printFloatSpecial(const std::string& input)
{
	std::string doubleSpecial = input.substr(0, input.length() - 1);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << std::endl;
	std::cout << "double: " << doubleSpecial << std::endl;
}

void ScalarConverter::printOutFloatRange(const std::string& input)
{
	std::string doubleSpecial = input.substr(0, input.length() - 1);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << doubleSpecial << std::endl;
}

void ScalarConverter::printFloat(const std::string& input)
{
	if (isFloatSpecial(input))
	{
		printFloatSpecial(input);
		return ;
	}
	double nbr;
	std::stringstream ss(input);
	ss >> nbr;
	if (nbr < -FLT_MAX || nbr > FLT_MAX)
	{
		printOutFloatRange(input);
		return ;
	}
	if (nbr < 0 || nbr > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(nbr)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nbr) << std::endl;
}

void ScalarConverter::printDoubleSpecial(const std::string& input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void ScalarConverter::printDouble(const std::string& input)
{
	if (isDoubleSpecial(input))
	{
		printDoubleSpecial(input);
		return ;
	}
	double nbr;
	std::stringstream ss(input);
	ss >> nbr;
	if (nbr < -DBL_MAX || nbr > DBL_MAX)
	{
		printOutOfRange();
		return ;
	}
	if (nbr < 0 || nbr > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(nbr)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nbr) << std::endl;
}