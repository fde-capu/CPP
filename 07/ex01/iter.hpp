/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/20 19:04:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <cstddef>

/*
** It seems is useless to have the same function running for each element if
** the function does not use the array value to process anything
** (though it might turn out to be usefull depending on context).
** Third ::iter() argument is "a function called for each element of the array";
** in this case, fun() without arguments, let's loop fun() array_length times.
** It is not mentined that after running the loop the array would be modified.
*/
template<typename T, typename F>
void iter(T * array, size_t array_length, F fun)
{
	std::cout << "[ A ]" << std::endl;
	(void)array;
	for (size_t i = 0; i < array_length; i++)
		fun();
	return ;
}

/*
** This works if the argument of fun is of the same type as the array.
** So the fun is called each with each array value as argument (seems logical).
** However, it is not mentioned that the function should be able
** to modify the array values.
*/
template<typename T, typename F>
void iter(T * array, size_t array_length, F fun(T))
{
	std::cout << "[ B ]" << std::endl;
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
	return ;
}

/*
** This function is called whenever the passed function "fun" has one argument
** consisting of a referente to "something" of the same type of the array.
** This also does not modify the original array, because no one asked.
*/
template<typename T, typename F>
void iter(T * array, size_t array_length, F fun(T &))
{
	std::cout << "[ C ]" << std::endl;
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
	return ;
}

/*
** In this case, the function has one arument of another type than the array.
** Seems useless, but might not be. It also does not take array[i] value into
** consideration, and does not modify the array. For this case, it is
** necessary that the iter function instantiates some variable of type A
** to pass as argument.
*/
template<typename T, typename F, typename A>
void iter(T * array, size_t array_length, F fun(A &))
{
	std::cout << "[ D ]" << std::endl;
	(void)array;
	A foo = 42;
	for (size_t i = 0; i < array_length; i++)
		fun(foo);
	return ;
}

/*
** Functions with more arguments than one?
** Variadic templates are C++11 (not allowed for this project).
*/

/*
** To take uninstantiated templates as function?
** Possible with "template template". Out of scope of this project.
*/

#endif
