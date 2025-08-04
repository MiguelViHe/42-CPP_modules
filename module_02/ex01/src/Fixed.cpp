/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/04 13:08:13 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath> // para roundf

// Constructor por defecto
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

// Constructor con int como parametro
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << FRACTIONAL_NUMBER;
}

// Constructor con float como parametro
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << FRACTIONAL_NUMBER));
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

// Setter
void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// convierte de fixedpoint to float
float Fixed::toFloat(void) const {
	return ((float)this->value / (1 << FRACTIONAL_NUMBER));
}

// convierte de fixedpoint to int
int Fixed::toInt(void) const {
	return (this->value >> FRACTIONAL_NUMBER);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}