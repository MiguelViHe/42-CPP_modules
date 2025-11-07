/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:21:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/07 17:18:49 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <ctime> // for std::tm
#include <fstream> // for std::ifstream
#include <sstream> // for std::stringstream
#include <cstring> // for std::memset

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates_db(other._rates_db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_rates_db = other._rates_db;
	}
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDatabase(std::string) const
{
	// Implementation to load the database from a CSV file
}

void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	// Implementation to process the input file
}

void	BitcoinExchange::print_output(std::string *key, double *value) const
{
	// Implementation to print output based on key and value
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	std::istringstream ss(date);
	std::string token;
	std::tm tm;

	std::memset(&tm, 0, sizeof(std::tm));
	int i = 0;
	int value = 0;
	while (std::getline(ss, token, '-'))
	{
		std::istringstream iss(token);
		iss >> value;
		if (i == 0)
			tm.tm_year = value - 1900; // Year empieza desde 1900
		else if (i == 1)
			tm.tm_mon = value - 1; // Month empieza desde 0
		else if (i == 2)
			tm.tm_mday = value;
		i++;
	}
	if (i != 3)
		return false;
	std::tm original_tm = tm;
	if (std::mktime(&tm) == -1) // Normaliza la estructura tm ajustandola con desbordes (ejemplo 32 de enero pasa a 1 de febrero). Devuelve -1 si la fecha es invalida por ejemplo año < 1900
		return false;
	if (tm.tm_year != original_tm.tm_year || tm.tm_mon != original_tm.tm_mon || tm.tm_mday != original_tm.tm_mday)
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& str, double& value) const
{
	if (str.empty())
		return false;

	// Check for invalid characters
	int dots = 0;
	int digits = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == '.')
		{
			dots++;
			if (dots > 1 || digits == 0)
				return false;
		}
		else if (std::isdigit(str[i]))
			digits++;
		else
			return false;
	}
	if (dots == 1 && digits < 2)
		return false;
	std::istringstream ss(str);
	ss >> value;
	if (ss.fail() || !ss.eof())
	return false;
	if (value < 0.0 || value > 1000.0)
		return false;
	return true;
}

double BitcoinExchange::getRateForDate(const std::string& date) const
{
	// Implementation to get the rate for a specific date
	return 0.0;
}