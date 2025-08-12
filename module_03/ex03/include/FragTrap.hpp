/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:22:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/12 14:22:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	static const int defaultHitPoints = 100;
	static const int defaultEnergyPoints = 100;
	static const int defaultAttackDamage = 30;

	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& rhs);
	~FragTrap();

	void highFivesGuys();
};

#endif