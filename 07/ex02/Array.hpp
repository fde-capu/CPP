/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:42:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/22 13:45:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <climits>

class ArrayException
{
	public:
		struct Error : public::std::exception
		{
			const char * what() const throw()
			{
				return "[ArrayException] Error.";
			}
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
		Array(void) : _size(0), element(0) {};

		Array(unsigned int n)
		{
			try
			{
				_size = static_cast<size_t>(n);
				element = new T[_size];
			}
			catch(std::exception&e)
			{
				// std::cout << e.what() << std::endl;
				throw ArrayException::Error();
			}
			element[0] = 7;
//			element[4] = 42;
		}

		Array(Array const & src) { *this = src; };

		Array &	operator= (Array const & rhs) {
			_size = rhs.size();
			for (size_t i = 0; i < rhs.size(); i++)
			{
//				setElement(i, rhs.getElement(i));
			}
			return *this;
		};

		~Array(void) {};
		size_t size() const { return _size; };
		T operator[] (size_t const u_index) const
		{
			if (u_index < 0 || u_index > _size)
				throw ArrayException::IndexOutOfRange();
			return element[static_cast<size_t>(u_index)];
		}

};

//std::ostream &	operator << (std::ostream & o, Array const & i);
template<typename T>
std::ostream & operator << (std::ostream & o, Array<T> const & self)
{
	o << "::Array:(" << self.size() << "):{";
	for (size_t i = 0; i < self.size(); i++)
	{
		o << self[i];
		if (i + 1 < self.size()) o << ",";
	}
	o << "}::";
	return o;
}

#endif
