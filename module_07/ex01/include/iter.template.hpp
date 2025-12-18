#ifndef ITER_TEMPLATE_HPP
#define ITER_TEMPLATE_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T* array, const size_t len, F func) {
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T, typename F>
void	iter(T const* array, const size_t len, F func) {
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

#endif