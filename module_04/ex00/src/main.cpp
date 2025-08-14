/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:03:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 14:47:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* d = new Dog();
		const Animal* c = new Cat();

		std::cout << d->getType() << " " << std::endl;
		std::cout << c->getType() << " " << std::endl;
		c->makeSound(); //will output the cat sound!
		d->makeSound();
		meta->makeSound();
		delete meta;
		delete d;
		delete c;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* d = new Dog();
		const WrongAnimal* c = new WrongCat();

		std::cout << d->getType() << " " << std::endl;
		std::cout << c->getType() << " " << std::endl;
		c->makeSound(); //will output the Animal sound!
		d->makeSound();
		meta->makeSound();
		delete meta;
		delete d;
		delete c;
	}
	std::cout << std::endl;
	{
		Dog dog;
		Cat cat;
		dog.makeSound();
		cat.makeSound();
	}
	std::cout << std::endl;
	{
		Animal* ptrDog = new Dog();
		Animal* ptrCat = new Cat();

		ptrDog->makeSound(); // Woof! (Dog::makeSound)
		ptrCat->makeSound(); // Meow! (Cat::makeSound)
		delete ptrDog; // llama Dog::~Dog() y luego Animal::~Animal()
		delete ptrCat; // llama Cat::~Cat() y luego Animal::~Animal()
	}
	std::cout << std::endl;
	{
		Cat cat;
		Dog dog;

		Animal& refDog = dog;
		Animal& refCat = cat;
		refDog.makeSound(); // Woof!
		refCat.makeSound(); // Meow!
	}
	return (0);
}