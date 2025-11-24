/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:19:12 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/24 13:03:59 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		int		_argc;
		char**	_argv;

		void	mergeVectors(std::vector<int>& small, std::vector<int>& large);
		void	movePairsVector(const std::vector<int>& source, std::vector<int>& small, std::vector<int>& large);
		void	sortVector(std::vector<int>& vec);
		void	fillVector(std::vector<int>& vec);
		void	mergeDeques(std::deque<int>& small, std::deque<int>& large);
		void	movePairsDeque(const std::deque<int>& source, std::deque<int>& small, std::deque<int>& large);
		void	sortDeque(std::deque<int>& dq);
		void	fillDeque(std::deque<int>& dq);
	
		public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
		void	validateArgv();
		void	sortWithVector();
		void	sortWithDeque();

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