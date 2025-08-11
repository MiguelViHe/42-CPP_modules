/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:18:05 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 12:28:36 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	public:	
		ClapTrap(const std::string& name);        // Constructor por defecto
		ClapTrap(const ClapTrap& other);          // Constructor de copia
		ClapTrap& operator=(const ClapTrap& rhs); // Operador de asignación
		~ClapTrap();                           // Destructor


		// SETTERS
		void setName(const std::string& name);
		void setHitPoints(const int& hitPoints);
		void setEnergyPoints(const int& energyPoints);
		void setAttackDamage(const int& attackDamage);
		// GETTERS
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;

		// Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif