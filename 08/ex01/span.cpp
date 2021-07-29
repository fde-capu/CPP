/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:18:35 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/29 10:45:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <sstream>

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

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
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
	
	std::list<int>::const_iterator h;
	for (h = begin; h != end; h++)
		addNumber(*h);
}

void Span::addNumber(Span const & ref)
{
	addNumber(ref.getBegin(), ref.getEnd());
}

unsigned int Span::shortestSpan() const
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

unsigned int Span::longestSpan() const
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

size_t Span::getLimit() const
{
	return limit_;
}

void Span::showElements() const
{
	std::stringstream o;
	o << "{ ";
	for (std::list<int>::const_iterator h = list_.begin(); h != list_.end(); std::advance(h, 1))
		o << *h << " ";
	o << "}";
	std::cout << o.str() << std::endl;
}

std::list<int>::const_iterator Span::getBegin() const
{
	return list_.begin();
}

std::list<int>::const_iterator Span::getEnd() const
{
	return list_.end();
}

Span & Span::operator= (Span const & rhs)
{
	if (this != &rhs)
	{
		this->limit_ = rhs.getLimit();
		this->addNumber(rhs);
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
