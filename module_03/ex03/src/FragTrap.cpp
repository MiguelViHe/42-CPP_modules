/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:22:41 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/12 16:06:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("defaultFrag")
{
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = FragTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = FragTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "FragTrap " << _name << " created" << std::endl;
	std::cout << _name << " : Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	ClapTrap::operator=(rhs);
	std::cout << "FragTrap " << _name << " assigned" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (_hitPoints <= 0) {
		std::cout << "FragTrap " << _name << " is out of hit points and cannot high five!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
