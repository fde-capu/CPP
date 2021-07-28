/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:18:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/28 16:29:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	private:
		size_t limit_;
	public:
		Span(unsigned int);
		void addNumber(int);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		Span(void);
		Span(Span const & src);
		Span &	operator = (Span const & rhs);
		~Span(void);
};

std::ostream &	operator << (std::ostream & o, Span const & i);

#endif
