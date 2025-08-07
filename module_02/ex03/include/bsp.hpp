/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:13:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/08/07 12:16:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
#define BSP_HPP

#include "Point.hpp"

// Función que determina si un punto está dentro de un triángulo
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // BSP_HPP