/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:38:41 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/12 16:06:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() 
	: ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
	std::cout << _name << " : Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	ClapTrap::operator=(rhs);
	_name = rhs._name;
	std::cout << "DiamondTrap " << _name << " assigned" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << _name << " is also ClapTrap " << ClapTrap::_name << std::endl;
}