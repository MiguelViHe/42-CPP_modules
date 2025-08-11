/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:14:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 15:12:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap humano("Ciri");
	humano.attack("Target1");
	humano.takeDamage(3);
	humano.beRepaired(2);

	ClapTrap humano2("Vin");
	humano2 = humano;
	humano2.attack("Target2");
	humano2.takeDamage(1);
	humano2.beRepaired(1);

	ScavTrap humano3("Geralt");
	humano3.attack("Target3");
	humano3.takeDamage(5);
	humano3.beRepaired(3);
	humano3.guardGate();

	ScavTrap humano4("Kelsier");
	humano4 = humano3; // Testing assignment operator
	humano4.attack("Target4");
	humano4.takeDamage(2);
	humano4.beRepaired(1);
	humano4.guardGate();

	ScavTrap humano5(humano3); // Testing copy constructor
	humano5.attack("Target5");
	humano5.takeDamage(5);
	humano5.beRepaired(10);
	return 0;
}