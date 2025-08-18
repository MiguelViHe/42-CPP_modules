/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:52:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/18 17:01:17 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		// return 0;
	}
	std::cout << "------------------------" << std::endl;
	{
		std::cout << "-----MediaSource tests-----" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "After learn Ice and Cure:" << std::endl;
		static_cast<MateriaSource*>(src)->printMaterias();
		std::cout << "After learn Ice, Cure, Ice, Cure added to the previous ones (out of range):" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		static_cast<MateriaSource*>(src)->printMaterias();
		ICharacter* me = new Character("me");
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();

		std::cout << "-----Character with materias equip and unequip tests-----" << std::endl;
		AMateria* tmp;
		std::cout << "equipping ice:" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();
		std::cout << "equipping cure:" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();
		std::cout << "equipping ice:" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();
		std::cout << "equipping cure:" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();
		std::cout << "equipping cure out of range 4:" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();
		std::cout << "unequipping 0, 3 and 4(out of range):" << std::endl;
		me->unequip(0);
		me->unequip(3);
		me->unequip(4);
		static_cast<Character*>(me)->printInventory();
		static_cast<Character*>(me)->printFloor();

		std::cout << "-----Use tests-----" << std::endl;
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob); // Invalid index
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "------------------------" << std::endl;
	{
		std::cout << "===== TEST 1: MateriaSource copy/assign =====" << std::endl;
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.printMaterias();

		std::cout << "\nConstruyendo src2 como copia de src (constructor de copia)..." << std::endl;
		MateriaSource src2(src);
		src2.printMaterias();

		std::cout << "\nCreando src3 vacío y asignándole src (operador=)..." << std::endl;
		MateriaSource src3;
		src3 = src;
		src3.printMaterias();


		std::cout << "\n===== TEST 2: Materia copy/assign =====" << std::endl;
		Ice ice1;
		Ice ice2(ice1);
		Cure cure1;
		Cure cure2;
		cure2 = cure1;

		std::cout << "ice1 type: " << ice1.getType() << std::endl;
		std::cout << "ice2 type: " << ice2.getType() << std::endl;
		std::cout << "cure1 type: " << cure1.getType() << std::endl;
		std::cout << "cure2 type: " << cure2.getType() << std::endl;


		std::cout << "\n===== TEST 3: Character copy/assign =====" << std::endl;
		Character bob("Bob");
		bob.equip(new Ice());
		bob.equip(new Cure());

		std::cout << "Bob's inventory:" << std::endl;
		bob.printInventory();

		std::cout << "\nConstruyendo alice como copia de bob (constructor de copia)..." << std::endl;
		Character alice(bob);   
		alice.printInventory();

		std::cout << "\nCreando tom vacío y asignándole bob (operador=)..." << std::endl;
		Character tom("Tom");
		tom = bob;
		tom.printInventory();
	}
}