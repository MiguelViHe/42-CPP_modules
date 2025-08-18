/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:46:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/18 16:25:39 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->_materia[i])
				delete this->_materia[i];
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;

	for (int i = 0; i < 4; i++) {
		if (!this->_materia[i]) {
			this->_materia[i] = m;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn " << m->getType() << std::endl;
	delete m; // Prevent memory leak if the materia cannot be learned
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] && this->_materia[i]->getType() == type) {
			return this->_materia[i]->clone();
		}
	}
	return NULL;
}

// For testing purposes
void MateriaSource::printMaterias() const {
	std::cout << "Materia Source:" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i])
			std::cout << "Slot " << i << ": " << this->_materia[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << ": empty" << std::endl;
	}
}
