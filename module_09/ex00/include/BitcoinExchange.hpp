/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:07:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2026/01/13 12:34:54 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

#define DB_FILE "data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	processInputFile(const std::string &filename) const; //process txt
		
		class HeaderException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::map<std::string, double> _rates_db; //como un diccionario donde la clave debe ser unica y el valor puede repetirse
		
		void	loadDatabase();
		bool	isValidDate(const std::string& date) const;
		bool	isValidValue(const std::string& str, double& value) const;
		double	getRateForDate(const std::string& date) const;
		void	print_output(const std::string &key, const double &value) const;
};

#endif