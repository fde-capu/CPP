/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/27 11:31:10 by fde-capu         ###   ########.fr       */
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
void iter(T * array, const size_t array_length, F fun)
{
//	std::cout << "[ A ]" << std::endl;
	(void)array;
	for (size_t i = 0; i < array_length; i++)
		fun();
	return ;
}

/*
** This catches all cases of a single-argument function.
** Array value is not changed, because no one asked.
*/
template<typename T, typename F, typename FA>
void iter(T * array, const size_t array_length, F fun(FA))
{
//	std::cout << "[ B ]" << std::endl;
	for (size_t i = 0; i < array_length; i++)
		fun(array[i]);
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
