/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:59:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 14:48:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	WrongAnimal::operator=(rhs);
	std::cout << "WrongCat assigned" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongMeow!" << std::endl;
}