/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:14:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 16:13:40 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap humano("Ciri");
	humano.attack("Target1");
	humano.takeDamage(3);
	humano.beRepaired(2);

	ClapTrap humano2("Geralt");
	humano2.attack("Target2");
	humano2.takeDamage(1);
	humano2.beRepaired(1);

	ScavTrap humano3("Vin");
	humano3.attack("Target3");
	humano3.takeDamage(5);
	humano3.beRepaired(3);
	humano3.guardGate();

	FragTrap humano4("Kaladin");
	humano4.attack("Target4");
	humano4.takeDamage(2);
	humano4.beRepaired(1);
	humano4.highFivesGuys();


	FragTrap humano5("Shallan");
	humano5 = humano4; // Testing assignment operator
	humano5.attack("Target5");
	humano5.takeDamage(3);
	humano5.beRepaired(5);
	humano5.highFivesGuys();

	FragTrap humano6(humano4);
	humano6.attack("Target6");
	humano6.takeDamage(5);
	humano6.beRepaired(10);
	humano6.highFivesGuys();

	FragTrap humano9(humano6);
	// humano9 = humano6; // Testing assignment operator
	humano9.attack("Target9");
	humano9.takeDamage(4);
	humano9.beRepaired(6);
	humano9.highFivesGuys();

	FragTrap humano10("Adolin");
	humano10 = humano5; // Testing assignment operator
	humano10.attack("Target10");
	humano10.takeDamage(4);
	humano10.beRepaired(6);
	humano10.highFivesGuys();

	return 0;

}