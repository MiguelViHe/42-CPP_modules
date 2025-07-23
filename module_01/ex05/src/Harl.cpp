/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:03:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 16:21:25 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){}
Harl::~Harl(void)
{
	std::cout << "Harl Destroyed." << std::endl;
}

//Private
void Harl::debug(void)
{
	std::cout << "DEBUG - I love having extra bacon for my 7XL-double-cheese-triple"
	<< "-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "INFO - I cannot believe adding extra bacon costs more money." 
	<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t"
	<< " be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "WARNING - I think I deserve to have some extra bacon for free. "
	<< "I’ve been coming for years, whereas you started working here"
	<< " just last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "ERROR - This is unacceptable! I want to speak to the"
	<< " manager now." << std::endl;
}

//Public
void	Harl::complain(std::string level)
{
	// Array de punteros a funciones miembro sin parámetros y que devuelven void
	void (Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	// Array de niveles
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "Mode doesn't exist. Try DEBUG, INFO, WARNING or ERROR" << std::endl;
}
