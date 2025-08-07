/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/07 12:30:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"


int main( int argc, char **argv ) {
	Point a;
	Point b(0, 5);
	Point c(5, 0);
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <x> <y>" << std::endl;
		return 1;
	}

	Point p(Fixed(std::stof(argv[1])), Fixed(std::stof(argv[2])));

	if (bsp(a, b, c, p))
		std::cout << "El punto está DENTRO del triángulo." << std::endl;
	else
		std::cout << "El punto está FUERA del triángulo o en el borde." << std::endl;

	return 0;
}