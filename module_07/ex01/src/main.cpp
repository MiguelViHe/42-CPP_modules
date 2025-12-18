/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:58:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/18 12:35:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.template.hpp"
#include "increase.template.hpp"
#include "print.template.hpp"
#include "utils.hpp"
#include <iostream>

int	main(void) {

	int array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print<int>);
	std::cout << std::endl;
	iter(array, 5, increase<int>);
	iter(array, 5, print<int>);
	std::cout << std::endl;

	//The function passed as the third parameter may take its argument
	//by const reference (array) or non-const reference (array4), 
	//depending on the context (int or int const).
	int const array4[] = {10, 20, 30, 40, 50};
	iter(array4, 5, print<int>);
	std::cout << std::endl;
	// iter(array4, 5, increase<int>); //Da error porque array4 es const y increase necesita un non-const reference
	iter(array4, 5, print<int>);
	std::cout << std::endl;

	char array2[] = {'a', 'b', 'c', 'd', 'e'};
	iter(array2, 5, print<char>);
	std::cout << std::endl;
	iter(array2, 5, increase<char>);
	iter(array2, 5, print<char>);
	std::cout << std::endl;
	iter(array2, 5, makeUpper);
	iter(array2, 5, print<char>);
	std::cout << std::endl;

	double array3[] = {4.3, 5.6, 6.7, 7.8, 8.9};
	iter(array3, 5, print<double>);
	std::cout << std::endl;
	iter(array3, 5, increase<double>);
	iter(array3, 5, print<double>);
	std::cout << std::endl;
	
	std::string strArray[] = {"hello", "world", "this", "is", "C++"};
	iter(strArray, 5, print<std::string>);
	std::cout << std::endl;
	iter(strArray, 5, increase<std::string>); //probar con 49 en el increase para ver que concatena un 1 en vez de sumar.
	iter(strArray, 5, print<std::string>);
	std::cout << std::endl;
	return (0);
}