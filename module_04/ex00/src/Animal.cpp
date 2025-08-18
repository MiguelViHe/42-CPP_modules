/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:43:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 16:03:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Unknown") {
	std::cout << "Animal created" << std::endl;
}
Animal::Animal(const std::string& type) : _type(type) {
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
		std::cout << "Animal assigned" << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed." << std::endl;
}

const std::string& Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "*Generic animal sound*" << std::endl;
}