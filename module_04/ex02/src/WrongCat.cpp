/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:59:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 14:53:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Brain.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"), _brain(new Brain()) {
	for (int i = 0; i < 100; ++i) {
		std::ostringstream oss;
		oss << "Idea " << i << " from Cat";
		this->_brain->setIdea(i, oss.str());
	}
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
		*this->_brain = *rhs._brain; // Deep copy
		std::cout << "WrongCat assigned" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
	delete _brain;
	std::cout << "WrongCat destroyed." << std::endl;
}

Brain& WrongCat::getBrain() const {
	return *_brain;
}

void WrongCat::makeSound() const {
	std::cout << "WrongMeow!" << std::endl;
}
