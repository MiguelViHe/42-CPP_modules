/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:55:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 14:48:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		std::cout << "Cat assigned" << std::endl;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}