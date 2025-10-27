/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.template.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:14:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 17:41:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_TEMPLATE_HPP
#define MAX_TEMPLATE_HPP

template <typename T>
T max(T arg1, T arg2) {
	return ((arg2 >= arg1) ? arg2 : arg1);
}

#endif