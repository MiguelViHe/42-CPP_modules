/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:03:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 15:43:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Brain.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		// DESCOMENTAR ABAJO UNA A UNA PARA PROBAR QUE DA ERROR DE COMPILACION POR SER CLASE ABSTRACTA
		// AAnimal a;
		// AAnimal a("Perro");
		// const AAnimal* meta = new Animal();
	}
	{
		const AAnimal* d = new Dog();
		d->makeSound();
		delete d;
		const AAnimal* c = new Cat();
		c->makeSound();
		delete c;
	}
	return (0);
}	