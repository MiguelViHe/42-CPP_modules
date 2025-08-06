/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:07:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/06 14:59:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	// Getters
	Fixed getX() const;
	Fixed getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};

#endif