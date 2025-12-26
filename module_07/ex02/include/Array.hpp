/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:16:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/26 10:24:50 by mvidal-h         ###   ########.fr       */
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
