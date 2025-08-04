/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:26 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/04 16:06:49 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:	
		Fixed();                            // Constructor por defecto
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& other);          // Constructor de copia
		Fixed& operator=(const Fixed& rhs); // Operador de asignación
		~Fixed();                           // Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Aritmética
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		// Comparación
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		// Incrememtos
		Fixed& operator++();     // pre-incremento
		Fixed operator++(int);   // post-incremento
		Fixed& operator--();
		Fixed operator--(int);

		// Funciones estáticas min / max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	private:
		int					value;
		static const int	FRACTIONAL_NUMBER = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
