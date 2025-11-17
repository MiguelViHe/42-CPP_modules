/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:21:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/17 10:01:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <ctime> // for std::tm
#include <fstream> // for std::ifstream
#include <sstream> // for std::stringstream
#include <cstring> // for std::memset
#include <algorithm>
#include "trim.hpp"

BitcoinExchange::BitcoinExchange() {
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates_db(other._rates_db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_rates_db = other._rates_db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDatabase()
{
	std::ifstream file(DB_FILE);
	if (!file.is_open())
		throw std::runtime_error("Could not open database file.");
	std::string line;
	std::getline(file, line); // Para saltar la cabecera
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, value_str;
		std::getline(iss, date, ',');
		std::getline(iss, value_str);
		if (date.empty() || value_str.empty()) //Si alguna parte esta vacia.
		{
			std::cerr << "Warning: Incomplete line in database: " << line << std::endl;
			continue;
		}
		if (!isValidDate(date)) //Si la fecha es invalida.
		{
			std::cerr << "Warning: Invalid date in database: " << line << std::endl;
			continue;
		}
		std::istringstream value_iss(value_str);
		double value;
		value_iss >> value;
		if (value_iss.fail() || !value_iss.eof()) // si la conversion falla (por ejemplo porque no es numérico) o no se ha leido todo (ejemplo "123abc")
		{
			std::cerr << "Warning: Invalid value in database: " << line << std::endl;
			continue;
		}
		_rates_db.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file " + filename);
	std::string line;
	std::getline(file, line);
	std::istringstream iss(line);
	std::string date, value_str;
	std::getline(iss, date, '|');
	std::getline(iss, value_str);
	if (date != "date " || value_str != " value")
		throw HeaderException();
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, value_str;
		std::getline(iss, date, '|');
		std::getline(iss, value_str);
		trim(date);
		trim(value_str);
		if (date.empty() || value_str.empty() || !isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		double value = 0.0;
		if (!isValidValue(value_str, value))
		{
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
		}
		print_output(date, value);
	}
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
		if (iss.fail() || !iss.eof())
			return false;
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

	// Checking for invalid characters
	int dots = 0;
	int digits = 0;
	size_t negative = 0;
	if (str[0] == '-')
		negative++;
	for (size_t i = negative ; i < str.size(); ++i)
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
	if (_rates_db.empty())
		return 0.0;
	std::map<std::string, double>::const_iterator it = _rates_db.lower_bound(date);
	if (it == _rates_db.begin())
		if (it->first != date)
			return 0.0;
	if (it == _rates_db.end() || it->first != date)
		--it;
	return it->second;
}

void	BitcoinExchange::print_output(const std::string &key, const double &value) const
{
	double rate = getRateForDate(key);
	double result = rate * value;
	std::cout << key << " => " << value << " = " << result << std::endl;
}

const char* BitcoinExchange::HeaderException::what() const throw()
{
	return "Error: Header \"Date | Value\" is missing in input file.";
}