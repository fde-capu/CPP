/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:48:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:40:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void memoryLeak()
{
	std::string* panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete panther; // That's all, folks!
}

void memoryLeak_solution2()
{
	// Made a concrete object instead of pointer.
	std::string panther = std::string("String panther (solution 2)");
	std::cout << panther << std::endl;
}

int	main(void)
{
	memoryLeak();
	memoryLeak_solution2();
}
