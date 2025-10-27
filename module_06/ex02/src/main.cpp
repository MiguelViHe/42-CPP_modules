/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:01:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/27 16:07:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "identify.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));

	Base* base = generate();
	Base* base2 = generate();
	Base* base3 = generate();

	identify(base);
	identify(*base);
	identify(base2);
	identify(*base2);
	identify(base3);
	identify(*base3);

	delete base;
	delete base2;
	delete base3;
	return (0);
}
