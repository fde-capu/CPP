/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:08:09 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:37:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int	main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
//	ponyOnTheHeap_withoutdelete();
	//	The above function is identical to ponyOnTheHeap(),
	//	but does not have 'delete'.
	//	Uncommento to test the expected leak.
	return 0;
}

void	ponyOnTheHeap_withoutdelete(void)
{
	Pony	*pony = new Pony;

	std::cout << "Heap (no deletion):" << std::endl;
	std::cout << pony->genus << " " << pony->epithet << std::endl;
	std::cout << "This will NOT be dellocated and will leak. Function made for demonstration." << std::endl;
	std::cout << std::endl;
	return ;
}
void	ponyOnTheHeap(void)
{
	Pony	*pony = new Pony;

	std::cout << "Heap (with deletion):" << std::endl;
	std::cout << pony->genus << " " << pony->epithet << std::endl;
	std::cout << "This will be manually dellocated." << std::endl;
	std::cout << std::endl;
	delete pony;
	return ;
}

void	ponyOnTheStack(void)
{
	Pony	pony;

	std::cout << "Stack:" << std::endl;
	std::cout << pony.genus << " " << pony.epithet << std::endl;
	std::cout << "This will be automatically dellocated." << std::endl;
	std::cout << std::endl;
	return ;
}
