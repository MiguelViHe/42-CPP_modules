/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:42:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 18:50:32 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "secureOpen.template.hpp"

int	ftReplace(std::string& line, const std::string& s1, const std::string& s2)
{
	std::size_t pos;
	while (true)
	{
		pos = line.find(s1);
		if (pos == std::string::npos)
			break;
		line.erase(pos, s1.length());
		line.insert(pos, s2);
	}
	return (0);
}

int	main(int argc, const char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;

	if (argc == 4)
	{
		if (secureOpen(std::string(argv[1]), infile) != 0) //std::ifstream infile(argv[1]); Esto al hacerlo en la declaración ya se encarga de abrirlo directamente.
			return (1);
		if (secureOpen(std::string(argv[1]) + ".replace", outfile) != 0)
			return (1);
		while (std::getline(infile, line))
		{
			ftReplace(line, std::string(argv[2]), std::string(argv[3]));
			outfile << line << std::endl;
		}
		infile.close();
		outfile.close();
	}
	else {
		std::cerr << "Uso: " << argv[0] << " <file> <s1> <s2>" << std::endl;
		return (1);
	}
}
