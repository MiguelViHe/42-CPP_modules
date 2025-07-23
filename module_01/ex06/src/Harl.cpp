/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:03:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 17:54:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){}
Harl::~Harl(void){}

//Private
void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl 
	<< "I love having extra bacon for my 7XL-double-cheese-triple"
	<< "-pickle-specialketchup burger. I really do!" << std::endl
	<< std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money."
	<< std::endl
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t"
	<< " be asking for more!" << std::endl
	<< std::endl;
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free."
	<< std::endl
	<< "I’ve been coming for years, whereas you started working here"
	<< " just last month." << std::endl
	<< std::endl;
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Level Harl::getLevel(const std::string& level)
{
	if (level == "DEBUG")   return (Level::DEBUG);
	if (level == "INFO")    return (Level::INFO);
	if (level == "WARNING") return (Level::WARNING);
	if (level == "ERROR")   return (Level::ERROR);
	return (Level::INVALID);
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
	switch (getLevel(level))
	{
	case DEBUG:
		(this->*funcs[DEBUG])();
	case INFO:
		(this->*funcs[INFO])();
	case WARNING:
		(this->*funcs[WARNING])();
	case ERROR:
	{
		(this->*funcs[ERROR])();
		break;
	}
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
