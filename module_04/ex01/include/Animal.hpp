/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:37:45 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 12:14:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const std::string& type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal(); //Tiene que ser virtual porque se va a borrar a través de un puntero a Animal que apunta a una clase derivada (Dog o Cat)

    void setType(const std::string& type);
    std::string getType() const;

    /*
    Animal* a = new Dog();
    a->makeSound();
    
    virtual ->Polimorfismo: el método correcto se elige en tiempo de ejecución según el objeto real.
    Sin virtual -> Llamada estática: se usa siempre el método de la clase base, incluso si el objeto real es de una clase derivada.*/
    virtual void makeSound() const; 

protected:
    std::string _type;
};

#endif