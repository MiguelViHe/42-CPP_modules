/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:35:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 15:13:23 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " copied\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    ClapTrap::operator=(rhs);
    std::cout << "ScavTrap " << _name << " assigned\n";
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destroyed\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
    std::cout << "ScavTrap " << _name << " ferociously attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!\n";
}
