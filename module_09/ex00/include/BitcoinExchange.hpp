/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:07:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/05 19:09:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

#define DB_FILE "../data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& dbFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	loadDatabase(std::string) const;
		void	processInputFile(const std::string &filename) const; //process txt
		void	print_output(std::string *key, double *value) const;

		//añadir aqui las exceptions
	private:
		std::map<std::string, double> _rates_db; //como un diccionario donde la clave debe ser unica y el valor puede repetirse

		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& str, double& value) const;
		double getRateForDate(const std::string& date) const;
};

#endif