/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:42:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/24 16:48:52 by fde-capu         ###   ########.fr       */
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
		T * element;
		size_t _size;
		void instantiate(unsigned int n)
		{
			try
			{
				_size = static_cast<size_t>(n);
				element = new T[_size];
				for (size_t i = 0; i < _size; i++)
					element[i] = T();
			}
			catch(const std::exception&e)
			{
				std::cout << "std::exception::" << e.what() << std::endl;
				throw ArrayException::Error();
			}
		};

	public:
		Array(void) : element(0), _size(0) {};

		Array(unsigned int n) {	instantiate(n);	};

		Array(Array const & src) { *this = src; };

		Array &	operator= (Array const & rhs) {
			if (this == &rhs) return *this;
			instantiate(static_cast<unsigned int>(rhs.size()));
			for (size_t i = 0; i < _size; i++)
				element[i] = rhs[i];
			return *this;
		};

		~Array(void) { delete [] element; };

		T & operator[] (size_t const u_index) const
		{
			if (u_index < 0 || u_index >= _size)
				throw ArrayException::IndexOutOfRange();
			return element[static_cast<size_t>(u_index)];
		}

		size_t size() const { return _size; };
};

template<typename T>
std::ostream & operator<< (std::ostream & o, Array<T> const & self)
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
