/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:55:53 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 15:45:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	for (int i = 0; i < 100; ++i) {
		std::ostringstream oss;
		oss << "Idea " << i << " from Dog";
		this->_brain->setIdea(i, oss.str());
	}
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copied." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		*this->_brain = *rhs._brain; // Deep copy
		std::cout << "Dog assigned." << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destroyed." << std::endl;
}

Brain& Dog::getBrain() const {
	return *this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
