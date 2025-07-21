/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:22:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/21 16:44:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "newZombie.hpp"
#include "randomChump.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("newZombie1");
	zombie1->announce();
	Zombie *zombie2 = newZombie("newZombie2");
	zombie2->announce();
	delete zombie1;
	delete zombie2;
	randomChump("Random Zombie1");
	randomChump("Random Zombie2");
}
