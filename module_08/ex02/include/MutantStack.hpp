/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:07:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/12/18 18:17:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	/* Definimos los nombres iterator, const_iterator, reverse_iterator y 
	const_reverse_iterator que seran de los mismos tipos que acabo de nombrar
	pero dentro del tipo de Container que corresponda en cada caso, ya que
	Container puede ser vector, list, deque (Container definido en el template)
	De esta manera podemos llamar a los iteradores con el nombre de la clase
	 (MutantStack) y no con el nombre del Container (deque, vector, list...) 
	 MutantStack<int>::iterator it -> y valdria para cualquier tipo de Container
	 std::deque<int>::iterator o un std::vector<int>::iterator dependiendo de
	 como instanciamos MutantStack */
	typedef typename Container::iterator iterator; //Defino un tipo llamado iterator que es exactamente el mismo tipo que Container::iterator
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	/* Definimos los metodos begin, end, rbegin, rend y sus versiones const
	que devuelven los iteradores correspondientes del contenedor subyacente
	(this->c) que es el contenedor protegido de std::stack.
	std::stack es como un alias de otros contenedores */
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP