/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:59:23 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/09/09 13:53:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter copied" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter assigned" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destroyed" << std::endl;
}

const char* ScalarConverter::InvalidInputException::what() const throw()
{
	return "Invalid input for conversion";
}

void ScalarConverter::convert(const std::string& literal)
{
	type valorType;

	valorType = parse(literal);
	if (valorType == ERROR)
		throw InvalidInputException();
	//seguir aqui
}