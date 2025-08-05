/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:51:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/05 14:38:59 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB {

	private:
		std::string	_name;
		Weapon*		_weapon; //CLAVE DEL EJERCICIO. Usamos puntero porque en B puede no tener arma y puntero puede ser null. (mirar en HUMANA)
		
	public:
		HumanB(const std::string& name);
		HumanB(const std::string& name, Weapon& w);
		~HumanB(void);
		//setters and getters
		const std::string&	getName(void) const;
		void				setWeapon(Weapon& weapon);
		//methods
		void				attack(void) const;
};

#endif