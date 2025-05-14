/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:12:55 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/13 17:47:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.utils.hpp"

std::string get_non_empty_input(const std::string& prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cerr << "Input error or end of input. Aborting." << std::endl;
			exit(1);
		}
		if (!input.empty())
			return (input);
		std::cout << "This field cannot be empty. Please try again.\n";
	}
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}