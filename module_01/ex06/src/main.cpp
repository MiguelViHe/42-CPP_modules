/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 17:46:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <Harl.hpp>

int	main(int argc, char **argv)
{
	Harl robot;
	
	if (argc == 2)
	{
		robot.complain(std::string(argv[1]));
		return (0);
	}
	else
	{
		std::cerr << "Uso: " << argv[0] << " <level>" << std::endl;
		return (1);
	}
}
