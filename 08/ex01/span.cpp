/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:18:35 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/29 09:05:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>

Span::Span(unsigned int i)
{
	limit_ = static_cast<size_t>(i);
	return ;
}

void Span::addNumber(int i)
{
	try
	{
		if (limit_ == list_.size())
			throw std::length_error("Limit reached.");
	}
	catch(std::exception&e)
	{
		std::cout << "Ouch! " << e.what() << std::endl;
		throw e;
	}
	
	list_.push_back(i);
}

void Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	try
	{
		if (limit_ < list_.size() + std::distance(begin, end))
			throw std::length_error("Range would break limits, nothing done.");
	}
	catch(std::exception&e)
	{
		std::cout << "Ouch! " << e.what() << std::endl;
		throw e;
	}
	
	std::list<int>::iterator h;
	for (h = begin; h != end; h++)
		addNumber(*h);
}

unsigned int Span::shortestSpan()
{
	try
	{
		if (list_.size() <= 1)
			throw std::length_error("List is too short.");
	}
	catch(std::exception&e)
	{
		std::cout << "Ouch! " << e.what() << std::endl;
		throw e;
	}

	unsigned int s(std::numeric_limits<unsigned int>::max());
	std::list<int>::const_iterator ha;
	std::list<int>::const_iterator hb;

	for (ha = list_.begin(); ha != list_.end(); ha++)
	{
		for (hb = list_.begin(); hb != list_.end(); hb++)
		{
			if (ha == hb) continue;
			s = static_cast<unsigned int>(std::abs(*ha - *hb)) < s ?
				static_cast<unsigned int>(std::abs(*ha - *hb)) : s;
		}
	}
	return s;
}

unsigned int Span::longestSpan()
{
	try
	{
		if (list_.size() <= 1)
			throw std::length_error("List is too short.");
	}
	catch(std::exception&e)
	{
		std::cout << "Ouch! " << e.what() << std::endl;
		throw e;
	}

	unsigned int s(std::numeric_limits<unsigned int>::min());
	std::list<int>::const_iterator ha;
	std::list<int>::const_iterator hb;

	for (ha = list_.begin(); ha != list_.end(); ha++)
	{
		for (hb = list_.begin(); hb != list_.end(); hb++)
		{
			if (ha == hb) continue;
			s = static_cast<unsigned int>(std::abs(*ha - *hb)) > s ?
				static_cast<unsigned int>(std::abs(*ha - *hb)) : s;
		}
	}
	return s;
}

unsigned int Span::getSize() const
{
	return list_.size();
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

Span & Span::operator= (Span const & rhs)
{
	if (this != &rhs)
	{
//		this->member = rhs.getMember();
	}
	return *this;
}

std::ostream & operator<< (std::ostream & o, Span const & self)
{
	o << "::Span::(size:" << self.getSize() << ")::";
	return o;
}

Span::~Span(void)
{
	return ;
}
