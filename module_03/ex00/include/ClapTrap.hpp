/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:18:05 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/08 12:23:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	public:	
		ClapTrap();                            // Constructor por defecto
		ClapTrap(const ClapTrap& other);          // Constructor de copia
		ClapTrap& operator=(const ClapTrap& rhs); // Operador de asignación
		~ClapTrap();                           // Destructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string	name;
		int    		points;
		int			energyPoints;
		int			attackDamage;
};

#endif