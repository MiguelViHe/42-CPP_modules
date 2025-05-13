/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:05:19 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/13 15:54:02 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
class	Contact {

	private:
		std::string _fname;
		std::string _lname;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
		
	public:
		Contact(void);
		~Contact(void);
		//setters and getters
		std::string get_fname(void) const;
		std::string get_lname(void) const;
		std::string get_nickname(void) const;
		std::string get_phone(void) const;
		std::string get_secret(void) const;
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nickname(std::string str);
		void		set_phone(std::string str);
		void		set_secret(std::string str);
		//methods
		void		print_summary(int index) const;
		void		print_details(void) const;
	};

#endif