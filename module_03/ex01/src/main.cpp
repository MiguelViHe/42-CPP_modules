/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:14:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 14:46:55 by mvidal-h         ###   ########.fr       */
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
	humano2.attack("Target2");
	humano2.takeDamage(10);
	humano2.beRepaired(1);

	ScavTrap humano3("Geralt");
	humano3.attack("Target3");
	humano3.takeDamage(5);
	humano3.beRepaired(3);

	return 0;
}