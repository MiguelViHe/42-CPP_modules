/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:58:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/10 15:07:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:

	enum type
	{
		CHAR,
		INT,
		DOUBLE,
		FLOAT,
		ERROR
	};

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	// parsers
	static type parse(const std::string& literal);

	// checkers
	static bool isInt(const std::string& input);
	static bool isFloat(const std::string& input);
	static bool isDouble(const std::string& input);
	static bool isChar(const std::string& input);
	static bool isFloatSpecial(const std::string& input);
	static bool isDoubleSpecial(const std::string& input);

	// printers
	static void printChar(const std::string& input);
	static void printInt(const std::string& input);
	static void printFloat(const std::string& input);
	static void printDouble(const std::string& input);
	static void printOutOfRange(void);
	static void printOutFloatRange(const std::string& input);
	static void printFloatSpecial(const std::string& input);
	static void printDoubleSpecial(const std::string& input);

public:
	static void convert(const std::string& literal);

	class InvalidInputException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};

#endif // SCALARCONVERTER_HPP