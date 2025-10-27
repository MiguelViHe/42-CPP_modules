/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:48:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 11:00:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

// reinterpret_cast sirve para convertir punteros a enteros y viceversa.
// Su utilidad principal es para pasar punteros, almacenarlos o transmitirlos
// como valores enteros sin perder la información de la dirección de memoria
// original.
int main(void)
{
	Data data = {1, "Ejemplo", 42.0};
	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Original Data: " << data.id << ", " << data.name << ", " << data.value << std::endl;
	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;
	std::cout << "Serialized Data (uintptr_t hex): 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "Deserialized Data: " << deserializedData->id << ", " << deserializedData->name << ", " << deserializedData->value << std::endl;
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;
	
	return 0;
}