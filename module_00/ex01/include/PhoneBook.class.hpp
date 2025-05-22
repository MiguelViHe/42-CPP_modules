/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:13:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/22 14:08:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
#include <iostream>
# include "Contact.class.hpp"
class	PhoneBook {

	private:
		Contact	_contacts[8];
		int		_contactCount;
		int		_totalContactAdd;
		
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;
		//Getters
		int		get_contactCount(void) const;
};

#endif