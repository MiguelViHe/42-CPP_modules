/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:46:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 16:10:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>// para rand y srand
#include <ctime> // para time
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int r = rand() % 3;
	switch (r)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		default:
			return new C();
	}
}

// Dynamic cast transforma un puntero o referencia de una clase base
// en un puntero o referencia de una clase derivada, si el objeto
// apuntado o referenciado es realmente de ese tipo derivado.
// Si no lo es, devuelve un puntero nulo (para punteros) o lanza
// una excepción std::bad_cast (para referencias).
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::bad_cast& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::bad_cast& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::bad_cast& e) {}

	std::cout << "Unknown" << std::endl;
}