/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:28:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/21 15:50:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
// # include <iomanip>
class	Zombie {

	private:
		std::string _name;
		
	public:
		Zombie(void);
		~Zombie(void);
		//setters and getters
		std::string get_name(void) const;
		void		set_name(std::string str);
		//methods
		void		announce(void);
	};

#endif