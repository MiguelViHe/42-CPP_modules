/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:05:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/18 16:43:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : _name(name), _floor(NULL) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : _name(other._name), _floor(NULL) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	FloorNode* current = other._floor;
	FloorNode* prev = NULL;
	while (current) {
		FloorNode* newNode = new FloorNode;
		newNode->materia = current->materia->clone();
		newNode->next = NULL;
		if (_floor == NULL)
			_floor = newNode;
		else
			prev->next = newNode;
		prev = newNode;
		current = current->next;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->_name = other._name;

		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}

		while (_floor) {
			FloorNode* tmp = _floor;
			delete _floor->materia;
			_floor = _floor->next;
			delete tmp;
		}
		_floor = NULL;
		
		FloorNode* current = other._floor;
		FloorNode* prev = NULL;
		while (current) {
			FloorNode* newNode = new FloorNode;
			newNode->materia = current->materia->clone();
			newNode->next = NULL;
			if (_floor == NULL)
				_floor = newNode;
			else
				prev->next = newNode;
			prev = newNode;
			current = current->next;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	while (_floor) {
			FloorNode* tmp = _floor;
			delete _floor->materia;
			_floor = _floor->next;
			delete tmp;
		}
}

std::string const& Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;

	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return;
		}
	}
	//I dont delete here because i'm not the owner of the materia.
	std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->_inventory[idx]) {
		FloorNode* newNode = new FloorNode;
		newNode->materia = this->_inventory[idx];
		newNode->next = _floor;
		_floor = newNode;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
	}
	else {
		std::cout << "No materia equipped in slot " << idx << std::endl;
	}
}

 // For testing purposes:
void Character::printInventory() const {
	std::cout << "Inventory of " << _name << ":" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			std::cout << "Slot " << i << ": " << _inventory[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << ": empty" << std::endl;
	}
}

void Character::printFloor() const {
	std::cout << "Floor of " << _name << ":" << std::endl;
	FloorNode* current = _floor;
	while (current) {
		std::cout << " - " << current->materia->getType() << std::endl;
		current = current->next;
	}
}