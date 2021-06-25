/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:28:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/23 10:33:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string brain("HI THIS IS BRAIN");
	std::string	*pointer_b = &brain;
	std::string	&referen_b = brain;
	std::cout << *pointer_b << std::endl;
	std::cout << referen_b << std::endl;
	return 0;
}
