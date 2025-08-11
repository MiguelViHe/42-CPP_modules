/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:57:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 12:29:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(40) {
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other.getName()),
	  _hitPoints(other.getHitPoints()),
	  _energyPoints(other.getEnergyPoints()),
	  _attackDamage(other.getAttackDamage()) 
{
	std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	std::cout << "ClapTrap " << _name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

//GETTERS AND SETTERS
void ClapTrap::setName(const std::string& name) {
	_name = name;
}

std::string ClapTrap::getName() const {
	return _name;
}

void ClapTrap::setHitPoints(const int& hitPoints) {
	_hitPoints = hitPoints;
}

int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

void ClapTrap::setEnergyPoints(const int& energyPoints) {
	_energyPoints = energyPoints;
}

int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

void ClapTrap::setAttackDamage(const int& attackDamage) {
	_attackDamage = attackDamage;
}

int ClapTrap::getAttackDamage() const {
	return _attackDamage;
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
}