/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:22:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/21 17:28:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

int main(void)
{
	int	n = 8;
	int	i = 0;

	Zombie *horde = zombieHorde(n, "mazmorreros");
	for (i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
}
