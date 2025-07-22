/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:04:17 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/22 15:32:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA {

	private:
		std::string	_name;
		Weapon&		_weapon; //CLAVE DEL EJERCICIO. Usamos referencia porque en A siempre va a haber arma (mirar en HUMANB)
		
	public:
		HumanA(const std::string& name, Weapon& w);
		~HumanA(void);
		//setters and getters
		const std::string&	getName(void) const;
		//methods
		void				attack(void) const;
};

#endif