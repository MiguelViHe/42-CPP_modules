/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 14:58:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath> // para roundf

// Constructor por defecto
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

// Constructor con int como parametro
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << FRACTIONAL_NUMBER;
}

// Constructor con float como parametro
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << FRACTIONAL_NUMBER));
}

// Constructor de copia
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

// Operador de asignación
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

// Setter
void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// convierte de fixedpoint to float
float Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << FRACTIONAL_NUMBER));
}

// convierte de fixedpoint to int
int Fixed::toInt(void) const {
	return (this->_value >> FRACTIONAL_NUMBER);
}

// Aritmética
Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;

	result.setRawBits(this->_value + rhs._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;

	result.setRawBits(this->_value - rhs._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed	result;

	long mult = static_cast<long>(this->_value) * static_cast<long>(rhs._value);
	result.setRawBits(static_cast<int>(mult >> FRACTIONAL_NUMBER)); // divide entre 256 para ajustar ya que al multiplicarlos directamente, cada uno ya habias sido multiplicado por 256, asi que nos sobra un 256
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;

	if (rhs._value == 0) {
		std::cerr << "Error: division by zero" << std::endl;
		return result;
	}
	long div = (static_cast<long>(this->_value) << FRACTIONAL_NUMBER) / rhs._value;
	result.setRawBits(static_cast<int>(div));
	return (result);
}

// Comparación
bool Fixed::operator>(const Fixed& rhs) const {
	return (this->_value > rhs._value);
}

bool Fixed::operator<(const Fixed& rhs) const {
	return (this->_value < rhs._value);
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(const Fixed& rhs) const {
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return (this->_value != rhs._value);
}

// Incrememtos
Fixed& Fixed::operator++() {
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed result(*this);
	this->_value += 1;
	return (result);
}

Fixed& Fixed::operator--(){
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed result(*this);
	this->_value -= 1;
	return (result);
}

// Funciones estáticas min / max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}

// Global
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}