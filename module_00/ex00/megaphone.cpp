/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:58:57 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/12 16:56:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype> // Para std::toupper

void	print_uppercase(const std::string &str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
		std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			print_uppercase(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}
