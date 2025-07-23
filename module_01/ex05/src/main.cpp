/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:50 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 16:41:12 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <Harl.hpp>

int	main(void)
{
	Harl robot;
	std::string complains[] = {"ERROR", "DEBUG", "WARNING", "INFO", "INFO", "WARNING", "ERROR", "NADA", "DEBUG"};
	std::size_t elems = 9;
	
	for(int i = 0; i < elems; i++)
		robot.complain(complains[i]);
	return (0);
} 