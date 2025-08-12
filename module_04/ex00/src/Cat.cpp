/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:55:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/12 16:37:32 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	Animal::operator=(rhs);
	std::cout << "Cat assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}