/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:40:33 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/14 15:09:16 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	Brain& getBrain() const;

	void makeSound() const; //COMENTAR ESTO PARA COMPROBAR QUE UNA CLASE DERIVADA DE UNA ABSTRACTA ESTA OBLIGADA A IMPLEMENTAR SUS METODOS VIRTUALES PUROS

private:
	Brain* _brain;
};

#endif