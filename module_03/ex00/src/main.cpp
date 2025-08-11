/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:14:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 12:24:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap humano("Ciri");
	humano.attack("Target1");
	humano.takeDamage(3);
	humano.beRepaired(2);

	ClapTrap humano2("Geralt");
	humano2.attack("Target2");
	humano2.takeDamage(5);
	humano2.beRepaired(3);

	ClapTrap humano3("Vin");
	humano3.attack("Target3");
	humano3.takeDamage(10);
	humano3.beRepaired(1);

	return 0;
}