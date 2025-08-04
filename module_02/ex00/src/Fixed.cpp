/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/04 11:11:40 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Constructor por defecto
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

// Constructor de copia
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

// Operador de asignación
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

// Setter
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

