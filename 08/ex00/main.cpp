/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:07:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/08/16 06:54:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>
#include <vector>
#include <deque>

int main ()
{
	std::cout << std::endl << "[ A ] std::list<int>" << std::endl;

	std::list<int> list;
	std::list<int>::iterator list_it;

	list.push_back(7);
	list.push_back(17);
	list.push_back(42);
	list.push_back(-117);

	list_it = ::easyfind(list, 42);
	if (list_it != list.end())
		std::cout << "Found. " << *list_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	list_it = ::easyfind(list, 8);
	if (list_it != list.end())
		std::cout << "Found. " << *list_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	list_it = ::easyfind(list, 4);
	if (list_it != list.end())
		std::cout << "Found. " << *list_it << std::endl;
	else
		std::cout << "Not found." << std::endl;



	std::cout << std::endl << "[ B ] std::vector<int>" << std::endl;

	std::vector<int> vector;
	std::vector<int>::iterator vector_it;

	vector.push_back(7);
	vector.push_back(17);
	vector.push_back(42);
	vector.push_back(-117);

	vector_it = ::easyfind(vector, 42);
	if (vector_it != vector.end())
		std::cout << "Found. " << *vector_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	vector_it = ::easyfind(vector, 8);
	if (vector_it != vector.end())
		std::cout << "Found. " << *vector_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	vector_it = ::easyfind(vector, 0);
	if (vector_it != vector.end())
		std::cout << "Found. " << *vector_it << std::endl;
	else
		std::cout << "Not found." << std::endl;



	std::cout << std::endl << "[ C ] std::deque<int>" << std::endl;

	std::deque<int> deque;
	std::deque<int>::iterator deque_it;

	deque.push_back(7);
	deque.push_back(17);
	deque.push_back(42);
	deque.push_back(-117);

	deque_it = ::easyfind(deque, 42);
	if (deque_it != deque.end())
		std::cout << "Found. " << *deque_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	deque_it = ::easyfind(deque, 8);
	if (deque_it != deque.end())
		std::cout << "Found. " << *deque_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	deque_it = ::easyfind(deque, 0);
	if (deque_it != deque.end())
		std::cout << "Found. " << *deque_it << std::endl;
	else
		std::cout << "Not found." << std::endl;

	return 0;
}
