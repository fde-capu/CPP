/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:18:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/29 10:28:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <list>
# include <iostream>

class Span
{
	private:
		std::list<int> list_;
		size_t limit_;
	public:
		Span(unsigned int);
		void addNumber(int);
		void addNumber(std::list<int>::const_iterator, std::list<int>::const_iterator);
		void addNumber(Span const &);
		void showElements() const;
		std::list<int>::const_iterator getBegin() const;
		std::list<int>::const_iterator getEnd() const;
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		unsigned int getSize() const;
		size_t getLimit() const;
		Span();
		Span(Span const &);
		Span & operator= (Span const &);
		~Span();
};

std::ostream & operator<< (std::ostream &, Span const &);

#endif
