/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:18:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/29 08:40:55 by fde-capu         ###   ########.fr       */
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
		void addNumber(std::list<int>::iterator, std::list<int>::iterator);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		unsigned int getSize() const;
		Span();
		Span(Span const &);
		Span & operator= (Span const &);
		~Span();
};

std::ostream & operator<< (std::ostream &, Span const &);

#endif
