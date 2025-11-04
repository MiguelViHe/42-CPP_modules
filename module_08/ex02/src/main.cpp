/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:07:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/04 12:29:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include<vector>

int main()
{
	{
		std::cout << "----- MutantStack with default container (deque) -----" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack); //Creamos un stack original a partir del MutantStack
		// MutantStack<int>::iterator it = s.begin(); //ERROR: al ser el original no tiene begin
		// MutantStack<int>::iterator ite = s.end(); //ERROR: al ser el original no tiene end
	}
	std::cout << "----- MutantStack with custom container (vector) -----" << std::endl;
	{
		MutantStack<std::string, std::vector<std::string>> mstackv;
		mstackv.push("Hello");
		mstackv.push("World");
		std::cout << mstackv.top() << std::endl;
		mstackv.pop();
		std::cout << mstackv.size() << " " <<mstackv.top() << std::endl;
		mstackv.push("C++");
		mstackv.push("module8");
		mstackv.push("ex02");
		MutantStack<std::string, std::vector<std::string>>::reverse_iterator rit = mstackv.rbegin();
		MutantStack<std::string, std::vector<std::string>>::reverse_iterator rite = mstackv.rend();
		while (rit < rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	return 0;
}