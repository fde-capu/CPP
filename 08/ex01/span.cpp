/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:18:35 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/28 16:30:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

Span::Span(unsigned int i)
: limit_(static_cast<size_t>(i))
{
	(void)limit_;
	return ;
}

void Span::addNumber(int i)
{
	(void)i;
}

unsigned int Span::shortestSpan()
{
	return 0;
}

unsigned int Span::longestSpan()
{
	return 0;
}

Span::Span(void)
{
	return ;
}

Span::Span(Span const & src)
{
	*this = src;
	return ;
}

Span & Span::operator = (Span const & rhs)
{
	if (this != &rhs)
	{
//		this->member = rhs.getMember();
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, Span const & self)
{
	o << "::Span::" << std::endl;
	(void)self;
	return o;
}

Span::~Span(void)
{
	return ;
}
