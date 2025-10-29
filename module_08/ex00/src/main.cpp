/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:59:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/10/29 17:48:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	{
		std::cout << "----- Test 1 -----" << std::endl;
		try {
			std::vector<int> v;
			v.push_back(1);
			v.push_back(10);
			v.push_back(42);
			std::vector<int>::iterator it;
			it = easyfind(v, 42);
			std::cout << "value " << *it << " found in position " << std::distance(v.begin(), it) << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "----- Test 2 -----" << std::endl;
		try {
			std::list<int> l;
			l.push_back(3);
			l.push_front(42);
			l.push_back(34);
			l.push_front(89);
			std::list<int>::iterator it;
			it = easyfind(l, 42);
			std::cout << "value " << *it << " found in position " << std::distance(l.begin(), it) << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "----- Test 3 -----" << std::endl;
		try {
			std::deque<int> d;
			d.push_back(3);
			d.push_back(42);
			d.push_front(34);
			d.push_front(89);
			std::deque<int>::iterator it;
			it = easyfind(d, 42);
			std::cout << "value " << *it << " found in position " << std::distance(d.begin(), it) << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	return (0);
}