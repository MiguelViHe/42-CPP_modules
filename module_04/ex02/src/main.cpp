/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:03:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 15:07:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void printIdeas(const Animal& animal)
{
	if (animal.getType() == "Dog")
	{
		const Dog& dog = static_cast<const Dog&>(animal);
		for (int i = 0; i < 100; ++i)
		{
			std::cout << dog.getBrain().getIdea(i) << std::endl;
		}
	}
	else if (animal.getType() == "Cat")
	{
		const Cat& cat = static_cast<const Cat&>(animal);
		for (int i = 0; i < 100; ++i)
		{
			std::cout << cat.getBrain().getIdea(i) << std::endl;
		}
	}
}

void printIdeasWrong(const WrongAnimal& animal)
{
	if (animal.getType() == "WrongCat")
	{
		const WrongCat& cat = static_cast<const WrongCat&>(animal);
		for (int i = 0; i < 100; ++i)
		{
			std::cout << cat.getBrain().getIdea(i) << std::endl;
		}
	}
}

int main(void)
{
	{
		// DESCOMENTAR ABAJO UNA A UNA PARA PROBAR QUE DA ERROR DE COMPILACION POR SER CLASE ABSTRACTA
		// Animal a;
		// Animal a("Perro");
		// const Animal* meta = new Animal();
	}
	{
		const Animal* d = new Dog();
		d->makeSound();
		delete d;
		const Animal* c = new Cat();
		c->makeSound();
		delete c;
	}
	return (0);
}	