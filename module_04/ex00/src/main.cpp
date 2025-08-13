/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:03:08 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/13 11:04:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
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