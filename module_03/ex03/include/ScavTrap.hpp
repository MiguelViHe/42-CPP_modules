/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:34:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/12 14:21:54 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	static const int defaultHitPoints = 100;
    static const int defaultEnergyPoints = 50;
    static const int defaultAttackDamage = 20;

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate(void);
};

#endif

