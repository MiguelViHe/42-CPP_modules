/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:14:57 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/28 12:22:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TEMPLATE_HPP
#define PRINT_TEMPLATE_HPP

#include <iostream>

template <typename T>
void	print(T const &val) {
	std::cout << val << " ";
}

#endif