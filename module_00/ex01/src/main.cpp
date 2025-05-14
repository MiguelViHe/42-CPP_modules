/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:02:34 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/13 18:00:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	main(void)
{
	PhoneBook 	pbook;
	std::string str;

	while (str != "EXIT")
	{
		std::cout << "Enter command you want to execute"
				  << " (ADD, SEARCH or EXIT)"
				  << std::endl;
		if (!std::getline(std::cin, str))
		{
			std::cerr << "Input error. Aborting." << std::endl;
			continue;
		}
		if (str == "ADD")
			pbook.add();
		else if (str == "SEARCH")
			pbook.search();
	}
	return (0);
}