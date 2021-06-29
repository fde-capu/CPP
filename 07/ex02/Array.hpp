/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:42:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/29 18:06:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array
{
	private:
		size_t _size;
		T * element;
	public:
		Array(void) : _size(0), element(0) {}; // Empty constructor.
		Array(unsigned int n) : _size(static_cast<size_t>(n))
		{
			element = new T[_size];
			element[0] = 7;
			element[4] = 42;
		}
		Array(Array const & src);
		Array &	operator = (Array const & rhs);
		~Array(void) {};
		size_t size() const { return _size; };
		T operator[] (long const u_index)
		{
			if (u_index < 0 || u_index > static_cast<long>(_size))
				throw std::range_error("Out of range.");
			return element[static_cast<size_t>(u_index)];
		}
};

#endif
