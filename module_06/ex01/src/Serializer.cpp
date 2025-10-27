/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:50:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 09:36:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer created" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer copied" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer assigned" << std::endl;
	return (*this);
}

Serializer::~Serializer() {
	std::cout << "Serializer destroyed" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}