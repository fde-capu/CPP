/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:19:10 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/29 10:54:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <cstdlib>

std::list<int> generate_random(unsigned int n)
{
	std::list<int> gen;
	int gen_n;

	for (unsigned int i = 0; i < n; i++)
	{
		gen_n = rand() % (n * 3);
		gen_n *= rand() % 2 ? 1 : -1;
		gen.push_back(gen_n);
	}
	return gen;
}

int main()
{
	std::cout << "[ A ] addNumber()." << std::endl;

	Span sp = Span(5);
	std::cout << sp << std::endl;

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;



	std::cout << std::endl << "[ B ] shortestSpan() and longestSpan()." << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;



	std::cout << std::endl << "[ C ] Limit reached." << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << "." << std::endl;
	}
	std::cout << sp << std::endl;



	std::cout << std::endl << "[ D ] Not enough members (0)." << std::endl;
	Span err_sp = Span(5);
	std::cout << err_sp << std::endl;
	try
	{
		std::cout << err_sp.shortestSpan() << std::endl;
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << "." << std::endl;
	}



	std::cout << std::endl << "[ E ] Not enough members (1)." << std::endl;
	err_sp.addNumber(42);
	std::cout << err_sp << std::endl;
	try
	{
		std::cout << err_sp.longestSpan() << std::endl;
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << "." << std::endl;
	}



	std::cout << std::endl << "[ F ] addNumber(iterator, iterator)." << std::endl;
	std::list<int> base;
	std::list<int>::iterator begin;
	std::list<int>::iterator end;
	base.push_back(11);
	base.push_back(-7);
	base.push_back(9);
	base.push_back(0);
	base.push_back(-20);
	base.push_back(4);
	begin = base.begin();
	end = base.end();

	Span sp_by_it = Span(10);
	sp_by_it.addNumber(begin, end);
	std::cout << sp_by_it << std::endl;
	std::cout << sp_by_it.shortestSpan() << std::endl;
	std::cout << sp_by_it.longestSpan() << std::endl;

	std::advance(begin, 1);
	std::advance(end, -2);
	sp_by_it.addNumber(begin, end);
	std::cout << sp_by_it << std::endl;
	std::cout << sp_by_it.shortestSpan() << std::endl;
	std::cout << sp_by_it.longestSpan() << std::endl;

	try
	{
		sp_by_it.addNumber(begin, end);
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << "." << std::endl;
	}
	std::cout << sp_by_it << std::endl;



	std::cout << std::endl << "[ G ] 10K+ elements." << std::endl;
	srand(time(NULL));
	std::list<int> rnd_list = generate_random(10001);
	Span sp_rnd = Span(10001);
	std::cout << sp_rnd << std::endl;
	sp_rnd.addNumber(rnd_list.begin(), rnd_list.end());
	std::cout << sp_rnd << std::endl;
	std::cout << sp_rnd.shortestSpan() << std::endl;
	std::cout << sp_rnd.longestSpan() << std::endl;



	std::cout << std::endl << "[ H ] Coplien." << std::endl;
	std::list<int> short_rnd = generate_random(20);
	Span rnd_sp = Span(21);
	rnd_sp.addNumber(short_rnd.begin(), short_rnd.end());

	Span dup1(rnd_sp);
	Span dup2 = rnd_sp;
	Span * dup3 = new Span(rnd_sp);

	std::cout << rnd_sp << std::endl;
	rnd_sp.showElements();
	std::cout << dup1 << std::endl;
	dup1.showElements();
	std::cout << dup2 << std::endl;
	dup2.showElements();
	std::cout << *dup3 << std::endl;
	dup3->showElements();

	rnd_sp.addNumber(0);
	dup1.addNumber(1);
	dup2.addNumber(2);
	dup3->addNumber(3);

	std::cout << rnd_sp << std::endl;
	rnd_sp.showElements();
	std::cout << dup1 << std::endl;
	dup1.showElements();
	std::cout << dup2 << std::endl;
	dup2.showElements();
	std::cout << *dup3 << std::endl;
	dup3->showElements();

	delete dup3;

	/// To do: Coplien, back to 20000.
}
