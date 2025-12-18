/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:34:49 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/18 15:25:00 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int main(void)
{
	std::cout << "Test 1: creation of an empty Array of ints" << std::endl;
	Array<int> intArray;
	std::cout << "Size: " << intArray.size() << std::endl;
	std::cout << "Print Array contents (intArray): " << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 2: creation of an Array of 5 ints" << std::endl;
	Array<int> intArray2(5);
	std::cout << "Size: " << intArray2.size() << std::endl;
	std::cout << "Print Array contents (intArray2): " << std::endl;
	for (unsigned int i = 0; i < intArray2.size(); i++) {
		std::cout << intArray2[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 3: filling Array (test 2) of 5 ints" << std::endl;
	srand(time(NULL));
	for (unsigned int i = 0; i < intArray2.size(); i++) {
		intArray2[i] = rand() % 100;
	}
	std::cout << "Print Array contents (intArray2): " << std::endl;
	for (unsigned int i = 0; i < intArray2.size(); i++) {
		std::cout << intArray2[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 4: constructor copy intArray3(intArray2)" << std::endl;
	Array<int> intArray3(intArray2);
	std::cout << "Size: " << intArray3.size() << std::endl;
	std::cout << "Print Array contents (intArray3): " << std::endl;
	for (unsigned int i = 0; i < intArray3.size(); i++) {
		std::cout << intArray3[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 5: assignment operator (intArray4 = intArray2)" << std::endl;
	Array<int> intArray4;
	intArray4 = intArray2;
	std::cout << "Size: " << intArray4.size() << std::endl;
	std::cout << "Print Array contents (intArray4): " << std::endl;
	for (unsigned int i = 0; i < intArray4.size(); i++) {
		std::cout << intArray4[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 6: out of bounds access" << std::endl;
	try {
		std::cout << "accessing index 10: (intArray2[10])" << std::endl;
		std::cout << intArray2[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		std::cout << "accessing index -1: (intArray2[-1])" << std::endl;
		std::cout << intArray2[-1] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 7: modification of Array elements" << std::endl;
	intArray2[3] = 4242;
	intArray3[4] = 424242;
	intArray4[2] = 42424242;
	std::cout << "Print Array contents (intArray2): ";
	for (unsigned int i = 0; i < intArray2.size(); i++) {
		std::cout << intArray2[i] << " ";
	}
	std::cout <<  std::endl;
	std::cout << "Print Array contents (intArray3): ";
	for (unsigned int i = 0; i < intArray3.size(); i++) {
		std::cout << intArray3[i] << " ";
	}
	std::cout <<  std::endl;
	std::cout << "Print Array contents (intArray4): ";
	for (unsigned int i = 0; i < intArray4.size(); i++) {
		std::cout << intArray4[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Test 8.1: creation of an Array of 3 strings (strArray(3))" << std::endl;
	Array<std::string> strArray(3);
	std::cout << "Size: " << strArray.size() << std::endl;
	for (unsigned int i = 0; i < strArray.size(); i++) {
		strArray[i] = "String_" + std::to_string(i);
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Test 8.2: creation of an Array of 5 strings (strArray2(5))" << std::endl;
	Array<std::string> strArray2(5);
	std::cout << "Size: " << strArray2.size() << std::endl;
	for (unsigned int i = 0; i < strArray2.size(); i++) {
		strArray2[i] = "Text_" + std::to_string(i);
		std::cout << strArray2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Test 8.3: Assignation of strArray2 on strArray 3 <- 5" << std::endl;
	strArray = strArray2;
	for (unsigned int i = 0; i < strArray.size(); i++) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "All tests done!" << std::endl;
	return (0);
}