/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secureOpen.template.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:25:18 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/23 18:47:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECURE_OPEN_HPP
#define SECURE_OPEN_HPP

#include <fstream>
#include <iostream>

template <typename Stream>
int secureOpen(const std::string& filename, Stream& stream)
{
	stream.open(filename.c_str());
	if (!stream) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return 1;
	}
	return 0;
}

#endif