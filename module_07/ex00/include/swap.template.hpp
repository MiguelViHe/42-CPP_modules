/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.template.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:59:00 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 17:43:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SWAP_TEMPLATE_HPP
#define SWAP_TEMPLATE_HPP

// Las function templates se usan para escribir una sola función genérica
// que pueda trabajar con diferentes tipos de datos sin tener que repetir
// el código para cada tipo.
template <typename T>
void swap(T &arg1, T &arg2) {
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

#endif

