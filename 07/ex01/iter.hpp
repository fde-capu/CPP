/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/07 11:13:19 by fde-capu         ###   ########.fr       */
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
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
	return ;
}

/*
** This function is called whenever the passed function "fun" has one argument
** consisting of a referente to "something" of the same type of the array.
** This also does not modify the original array, for this was not mentioned.
*/
template<typename T, typename F>
void iter(T * array, size_t array_length, F fun(T &))
{
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
	return ;
}

/*
** Now, if the function gets as argument something another type than the array.
** Seems useless (but might not be). It also does not takt array[i] value into
** consideration, and does not modify the array.
*/
template<typename T, typename F, typename FT>
void iter(T * array, size_t array_length, F fun(FT &))
{
	(void)array;
	FT foo = 42;
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
