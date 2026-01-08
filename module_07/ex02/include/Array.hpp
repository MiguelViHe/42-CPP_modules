/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:16:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2026/01/08 16:06:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array<T>& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	T& operator[](unsigned int index) const;
	unsigned int	size() const;

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	T* _array;
	unsigned int _size;
};

#include "Array.tpp"

#endif // ARRAY_HPP
