/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:11:00 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 17:27:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl {

	public:
		//Enums
		enum Level
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			INVALID
		};	
	
		Harl(void);
		~Harl(void);
		//setters and getters
		//methods
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		static Level getLevel(const std::string& level);
};

#endif