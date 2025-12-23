/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:55:51 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/23 17:21:09 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : _array(new T[other._size]()), _size(other._size) {
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		if (_size != other._size) {
			delete[] _array;
			_size = other._size;
			_array = new T[_size](); //el parentesis al final activa la inicializacion a los valores por defecto automatica.
		}
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index < 0 || index >= _size) {
		throw OutOfBoundsException();
	}
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Index out of bounds";
}