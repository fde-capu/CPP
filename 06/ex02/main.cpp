/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:33:18 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/17 18:24:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iomanip>

int random_int(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

Base * generate(void)
{
	int r = random_int('A', 'C');
	Base * gen;
	if (r == 'A')
	{
		std::cout << "generate (random): Base * gen = new A(); >> A" << std::endl;
		gen = new A();
	}
	if (r == 'B')
	{
		std::cout << "generate (random): Base * gen = new B(); >> B" << std::endl;
		gen = new B();
	}
	if (r == 'C')
	{
		std::cout << "generate (random): Base * gen = new C(); >> C" << std::endl;
		gen = new C();
	}
	return gen;
}

void identify(Base* p)
{
	char id = 0;
	A * comp_a = dynamic_cast<A *>(p); // dynamic_cast returns NULL if fail.
	B * comp_b = dynamic_cast<B *>(p);
	C * comp_c = dynamic_cast<C *>(p);
	if (comp_a == p) id = 'A';
	if (comp_b == p) id = 'B';
	if (comp_c == p) id = 'C';
	std::cout << "                      identify(Base * p) >> " << id << std::endl;
	return ;
}

void identify(Base& p)
{
	// identify(&p); // subject.pdf does not prohibit this, though:
	char id = 'A';
	try
	{
		dynamic_cast<A&>(p);
	}
	catch(std::exception & e)
	{
		try
		{ 
			id = 'B';
			dynamic_cast<B&>(p);
		}
		catch(std::exception & e) { id = 'C'; }
	}
	std::cout << "                      identify(Base & p) >> " << id << std::endl;
}

int main()
{
	std::cout << std::endl;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 10; i++)
	{
		Base * gen = generate();
		identify(gen);
		identify(*gen);
		delete gen;
		std::cout << std::endl;
	}
	return 0;
}
