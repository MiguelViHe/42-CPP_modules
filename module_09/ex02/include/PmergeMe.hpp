/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:19:12 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/11/27 15:59:25 by mvidal-h         ###   ########.fr       */
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

		// VECTORS
		void				mergeVectors(std::vector<int>& small, std::vector<int>& large);
		void				movePairsVector(const std::vector<int>& source, std::vector<int>& small, std::vector<int>& large);
		void				sortVector(std::vector<int>& vec);
		void				fillVector(std::vector<int>& vec);
		void				printVector(const std::vector<int>& vec, std::string msg, bool full);
		std::vector<int>	generateJacobsthalOrderVector(int n);
		// DEQUES
		void				mergeDeques(std::deque<int>& small, std::deque<int>& large);
		void				movePairsDeque(const std::deque<int>& source, std::deque<int>& small, std::deque<int>& large);
		void				sortDeque(std::deque<int>& dq);
		void				fillDeque(std::deque<int>& dq);
		void				printDeque(const std::deque<int>& dq, std::string msg, bool full);
		std::deque<int>		generateJacobsthalOrderDeque(int n);
	
		public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
		void	validateArgv();
		double	sortWithVector();
		double	sortWithDeque();
		bool	isVectorSorted(const std::vector<int>& vec);
		bool	isDequeSorted(const std::deque<int>& dq);

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