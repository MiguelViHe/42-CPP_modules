/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:43:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 16:07:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unknown") {
	std::cout << "AAnimal created" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
	std::cout << "AAnimal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
		std::cout << "AAnimal assigned" << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destroyed." << std::endl;
}

const std::string& AAnimal::getType() const {
	return _type;
}
