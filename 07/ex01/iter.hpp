/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/25 11:31:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <cstddef>

template<typename T, typename F>
void iter(T * array, size_t array_length, F & fun)
/*
** It seems is useless to have the same function running for each element if
** the function does not use the array value to process anything (it seems but
** it might turn out to be usefull depending on context).
** Third ::iter() argument is "a function called for each element of the array";
** in this case, fun() without arguments, let's loop fun() array_length times.
** It is not mentined that after running the loop the array would be modified.
*/
{
	(void)array;
	for (size_t i = 0; i < array_length; i++)
		fun();
	return ;
}

template<typename T, typename F>
void iter(T * array, size_t array_length, F fun(T))
/*
** This works if the argument of fun is of the same type as the array.
** So the fun is called each with each array value as argument (seems logical).
** However, it is not mentioned that the function should be able
** to modify the array values.
*/
{
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
	return ;
}

template<typename T, typename F>
void iter(T * array, size_t array_length, F fun(T &))
/*
** This function is called whenever the passed function "fun" has one argument
** consisting of a referente to "something" of the same type of the array.
** This also does not modify the original array, for this was not mentioned.
*/
{
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
	return ;
}

#endif
