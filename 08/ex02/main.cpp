/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:06:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/08/12 15:59:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include "hex_dump.hpp"
#include <list>
#include <stack>

void listmain()
{
	std::list<int> lstack;

	lstack.push_back(5); // (bottom) {5} (top)
	lstack.push_back(17); // {5, 17}

	std::cout << lstack.back() << std::endl; // Returns & top == 17. << 17

	lstack.pop_back(); // Removes top; // {5}
	std::cout << lstack.size() << std::endl; // << Size: 1

	lstack.push_back(3); // {5, 3}
	lstack.push_back(5); // {5, 3, 5}
	lstack.push_back(737); // {5, 3, 5, 737}
	//[...]
	lstack.push_back(0); // {5, 3, 5, 737, 0}

	std::list<int>::iterator it = lstack.begin(); // &[0]
	std::list<int>::iterator ite = lstack.end(); // &[5] (&[4] + 1)

	++it; // &[1]
	--it; // &[0]
	while (it != ite) // [0]-[4] << 5 3 5 737 0
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(lstack); // Initialize std::stack passing std::list? No-no.
}

int main()
{
	std::cout << std::endl << "[ A ] Test with std::list." << std::endl;
	listmain();


	std::cout << std::endl << "[ B ] Test with MutantStack." << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << "mstack:" << std::endl;
	hex_dump<MutantStack<int> >(mstack);

	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "it:" << std::endl;
	hex_dump<MutantStack<int>::iterator>(it);

	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "ite:" << std::endl;
	hex_dump<MutantStack<int>::iterator>(ite);

	std::cout << std::hex << "ite(" << (void *)&ite << ") - it(" << (void *)&it << ") = " << std::dec << (ite - it) << std::endl;

	++it;
	std::cout << "After ++it:" << std::endl;
	hex_dump<MutantStack<int>::iterator>(it);

	--it;
	std::cout << "After --it:" << std::endl;
	hex_dump<MutantStack<int>::iterator>(it);

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return 0;
}
