/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:26 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/11 11:23:23 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:	
		Fixed();                            // Constructor por defecto
		Fixed(const Fixed& other);          // Constructor de copia
		Fixed& operator=(const Fixed& rhs); // Operador de asignación
		~Fixed();                           // Destructor

		int  getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int                 _value;
		static const int    FRACTIONAL_NUMBER = 8;
};

#endif
