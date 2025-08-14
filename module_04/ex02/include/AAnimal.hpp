/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:37:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 15:23:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
public:
	AAnimal();
	AAnimal(const std::string& type);
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal(); //Tiene que ser virtual porque se va a borrar a través de un puntero a Animal que apunta a una clase derivada (Dog o Cat)

	std::string getType() const;

	/*
	AAnimal* a = new Dog();
	a->makeSound();
	
	virtual ->Polimorfismo: el método correcto se elige en tiempo de ejecución según el objeto real.
	Sin virtual -> Llamada estática: se usa siempre el método de la clase base, incluso si el objeto real es de una clase derivada.*/
	virtual void makeSound() const = 0; //Indica que este método debe ser implementado en las clases derivadas obligatoriamente.

protected:
	std::string _type;
};

#endif