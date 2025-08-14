/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:03:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 12:10:43 by mvidal-h         ###   ########.fr       */
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
		const int SIZE = 6;
		Animal* animals[SIZE];
	
		for (int i = 0; i < SIZE; ++i) {
			if (i < SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl << "--- Making sounds ---" << std::endl;
		for (int i = 0; i < SIZE; ++i) {
			animals[i]->makeSound();
		}
		std::cout << std::endl << "--- Deleting animals ---" << std::endl;
		for (int i = 0; i < SIZE; ++i) {
			delete animals[i]; //destroy animal brain and cat or dog just deleting Animal.
		}
	}
	{
		std::cout << std::endl << "--- Deep copy test ---" << std::endl;
		Cat c1;
		std::cout << "Original Cat Ideas:" << std::endl;
		printIdeas(c1);
		c1.getBrain().setIdea(0, "I want my fish");
		c1.getBrain().setIdea(1, "I want to chase the mouse");
		std::cout << "Modified Cat Ideas:" << std::endl;
		printIdeas(c1);
		Cat c2(c1);
		std::cout << "Copied Cat Ideas (c2):" << std::endl;
		printIdeas(c2);
		Cat c3;
		c3 = c1;
		std::cout << "Assigned Cat Ideas (c3):" << std::endl;
		printIdeas(c3);
		c1.makeSound();
		c2.makeSound();
		c3.makeSound();
	}
	{
		std::cout << std::endl << "--- WrongAnimal and WrongCat test polimorfism---" << std::endl;
		const WrongAnimal* animal = new WrongCat();
		animal->makeSound();
		delete animal;
		// Cambiar a virtual en el destructor y en el método makeSound de WrongAnimal y volver a probar. probar ambos casos con valgrind
	}
	return (0);
}