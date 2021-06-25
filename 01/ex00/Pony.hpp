/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:27:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/22 16:35:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class	Pony
{
	public:
		Pony(void);
		~Pony(void);
		std::string genus;
		std::string epithet;
};

void	ponyOnTheHeap(void);
void	ponyOnTheStack(void);
void	ponyOnTheHeap_withoutdelete(void);

#endif
