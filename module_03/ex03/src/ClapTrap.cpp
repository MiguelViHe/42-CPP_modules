/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:57:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/12 13:15:41 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() 
	: _name("defaultClap"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0) {
		  std::cout << "ClapTrap " << _name << " created." << std::endl;
		  std::cout << _name << ": Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage) 
{
	std::cout << "ClapTrap " << _name << " copied." << std::endl;
	std::cout << _name << " copied: Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assigned." << std::endl;
	std::cout << _name << " assigned: Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already out of hit points!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0) {
		_hitPoints = 0;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount 
			  << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
	std::cout << _name << " : Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left to be repaired!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount 
			  << " hit points! New hit points: " << _hitPoints << std::endl;
	std::cout << _name << " : Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << std::endl;
}