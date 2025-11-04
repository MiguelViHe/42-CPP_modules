/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:25:38 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/04 12:07:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() 
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other) 
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) 
{
	std::cout << "MutantStack assignment operator called" << std::endl;
	if (this != &other) {
		std::stack<T, Container>::operator=(other);
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}
