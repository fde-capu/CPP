/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:42:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/08 08:16:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

class ArrayException
{
	public:
		struct InvalidConstructorParameter : public std::exception
		{
			const char * what() const throw()
			{
				return "[ArrayException] Runtime: construtor may ONLY have 'unsigned int' compatible parameter.";
			};
		};
		struct IndexOutOfRange : public std::exception
		{
			const char * what() const throw()
			{
				return "[ArrayException] Runtime: Index out of range.";
			};
		};
};

template<typename T>
class Array
{
	private:
		size_t _size;
		T * element;
	public:
		Array(void) : _size(0), element(0) {}; // Empty constructor (mandatory).
		template<typename N> // Accept all types so it can reject all but one.
		Array(N n) : _size(n)
		{
			if (n < 0 || 											// If it is signed...
				sizeof(N) != sizeof(unsigned int) ||				// ...or not compatible...
				static_cast<N>(static_cast<unsigned int>(n)) != n)	// ...or strange to unsigned int.
				throw ArrayException::InvalidConstructorParameter();
			element = new T[_size];
			element[0] = 7;
			element[4] = 42;
		}
		Array(Array const & src);
		Array &	operator= (Array const & rhs);
		~Array(void) {};
		size_t size() const { return _size; };
		T operator[] (long const u_index)
		{
			if (u_index < 0 || u_index > static_cast<long>(_size))
				throw ArrayException::IndexOutOfRange();
			return element[static_cast<size_t>(u_index)];
		}
};

#endif
