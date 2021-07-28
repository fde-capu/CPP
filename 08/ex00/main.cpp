/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:07:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/28 14:47:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <vector>
#include <string>

int main ()
{
	std::list<int> list;
	list.push_back(7);
	list.push_back(17);
	list.push_back(42);
	list.push_back(-117);

	std::list<int>::iterator head_it;
	
	head_it = ::easyfind(list, 42);
//	head_it = std::find(list.begin(), list.end(), 42);
	std::cout << "Finds 42 >> " << *head_it << std::endl;
	if (head_it != list.end())
		std::cout << "Found." << std::endl;
	else
		std::cout << "Not found." << std::endl;

	head_it = ::easyfind(list, 8);
//	head_it = std::find(list.begin(), list.end(), 8);
	std::cout << "Finds 42 >> " << *head_it << std::endl;
	if (head_it != list.end())
		std::cout << "Found." << std::endl;
	else
		std::cout << "Not found." << std::endl;


//	head_it = ::easyfind(list, 8);
//	std::cout << "Finds >> " << *head_it << " << is (size) past the last element:" << std::endl;
//	std::cout << "list.end() " << *list.end() << std::endl;
//	if (head_it)
//		std::cout << "Found." << std::endl;
//	else
//		std::cout << "Not found." << std::endl;

	return 0;
}
