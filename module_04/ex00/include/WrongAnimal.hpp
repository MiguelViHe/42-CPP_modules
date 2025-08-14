/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:53:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 14:47:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const std::string& type);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    std::string getType() const;

    /*
    virtual ->Polimorfismo: el método correcto se elige en tiempo de ejecución según el objeto real.
    Sin virtual -> Llamada estática: se usa siempre el método de la clase base, incluso si el objeto real es de una clase derivada.
    */
    void makeSound() const;

protected:
    std::string _type;
};

#endif
