/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:57:36 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/22 12:07:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {

	private:
		std::string _type;
		
	public:
		Weapon(void);
		Weapon(const std::string& type);
		~Weapon(void);
		//setters and getters
		const std::string&	getType(void) const;
		void				setType(std::string str);
		//methods
};

#endif