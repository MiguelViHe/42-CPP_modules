/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.template.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:14:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 17:41:25 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_TEMPLATE_HPP
#define MIN_TEMPLATE_HPP

template <typename T>
T min(T arg1, T arg2) {
	return ((arg2 <= arg1) ? arg2 : arg1);
}

#endif