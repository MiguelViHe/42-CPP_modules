/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:28:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/12 16:58:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trim.hpp"

void trim(std::string &s) {
    std::string::size_type start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;

    std::string::size_type end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;

    s = s.substr(start, end - start);
}