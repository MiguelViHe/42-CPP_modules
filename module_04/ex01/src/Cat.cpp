/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:55:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 11:13:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	for (int i = 0; i < 100; ++i) {
		std::ostringstream oss;
		oss << "Idea " << i << " from Cat";
		this->_brain->setIdea(i, oss.str());
	}
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain); // Deep copy
		std::cout << "Cat assigned" << std::endl;
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destroyed." << std::endl;
}

Brain& Cat::getBrain() const {
	return *this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}