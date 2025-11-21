/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:19:12 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/21 15:01:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>

class PmergeMe
{
	private:
		int		_argc;
		char**	_argv;
	
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
		void	validateArgv();
		void	sortVector();
		void	sortDeque();

		class PmergeMeException : public std::exception
		{
		private:
			std::string _message;

		public:
			// Constructor que permite crear mensajes personalizados
			PmergeMeException(const std::string &msg) : _message(msg) {}

			// Destructor (throw() necesario por compatibilidad con std::exception)
			virtual ~PmergeMeException() throw() {}

			virtual const char* what() const throw();
		};
};
#endif