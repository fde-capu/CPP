/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:19:10 by fde-capu          #+#    #+#             */
/*   Updated: 2021/08/12 15:09:38 by fde-capu         ###   ########.fr       */
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
		gen_n = rand() % (n * 30);
		gen_n *= rand() % 2 ? 1 : -1;
		gen.push_back(gen_n);
	}
	return gen;
}

bool ft_confirm(std::string msg, bool def)
{
	std::string answer;

	std::cout << msg;
	if (def)
		std::cout << " [Y] ";
	else
		std::cout << " [N] ";
	std::getline(std::cin, answer);
	return answer != "" ? !def : def;
}

int main()
{
	std::cout << "[ A ] addNumber()." << std::endl;

	Span sp = Span(5);
	std::cout << sp << std::endl;
	sp.showElements();

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	sp.showElements();



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
		std::cout << "Controled error: " << e.what() << std::endl;
	}
	std::cout << sp << std::endl;


	Span err_sp = Span(5);
	std::cout << err_sp << std::endl;
	try
	{
		std::cout << err_sp.shortestSpan() << std::endl;
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << std::endl;
	}


	err_sp.addNumber(42);
	std::cout << err_sp << std::endl;
	try
	{
		std::cout << err_sp.longestSpan() << std::endl;
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << std::endl;
	}



	std::cout << std::endl << "[ D ] addNumber(iterator, iterator)." << std::endl;
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
	end = base.end(); // Basic list.

	Span sp_by_it = Span(15);
	sp_by_it.addNumber(begin, end); // addNumber by pair of iterators.
	std::cout << sp_by_it << std::endl;
	sp_by_it.showElements();
	std::cout << sp_by_it.shortestSpan() << std::endl;
	std::cout << sp_by_it.longestSpan() << std::endl;
	std::cout << std::endl;

	std::advance(begin, 1);
	std::advance(end, -2);
	sp_by_it.addNumber(begin, end); // Other iterator positions.
	std::cout << sp_by_it << std::endl;
	sp_by_it.showElements();
	std::cout << sp_by_it.shortestSpan() << std::endl;
	std::cout << sp_by_it.longestSpan() << std::endl;
	std::cout << std::endl;

	sp_by_it.addNumber(sp); // Add by passing another Span (bonus).
	std::cout << sp_by_it << std::endl;
	sp_by_it.showElements();
	std::cout << sp_by_it.shortestSpan() << std::endl;
	std::cout << sp_by_it.longestSpan() << std::endl;
	std::cout << std::endl;

	try
	{
		sp_by_it.addNumber(begin, end);
		// sp_by_it.addNumber(sp);
	}
	catch (std::exception&e)
	{
		std::cout << "Controled error: " << e.what() << std::endl;
	}
	std::cout << sp_by_it << std::endl;
	sp_by_it.showElements();

	std::cout << std::endl << "[ F ] 10K+ elements." << std::endl;
	srand(time(NULL));
	std::list<int> rnd_list = generate_random(10001);
	Span sp_rnd = Span(10001);
	std::cout << sp_rnd << std::endl;
	sp_rnd.addNumber(rnd_list.begin(), rnd_list.end());
	std::cout << sp_rnd << std::endl;
	std::cout << sp_rnd.shortestSpan() << std::endl;
	std::cout << sp_rnd.longestSpan() << std::endl;



	std::cout << std::endl << "[ G ] James O. \"Cope\" Coplien's Canonical Orthodoxy demo." << std::endl;
	{
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
	}


	std::cout << std::endl << "[ H ] Now really: 100K+ elements." << std::endl;
	if (ft_confirm("Spanning this many elements takes aprox. 6 min. on i7-6700(8)@4KGHz. Are you sure?", 0))
	{
		srand(time(NULL));
		std::list<int> hundred_thousand_one = generate_random(100001);
		Span sp_hto = Span(100001);
		std::cout << sp_hto << std::endl;
		sp_hto.addNumber(hundred_thousand_one.begin(), hundred_thousand_one.end());
		std::cout << sp_hto << std::endl;
		std::cout << sp_hto.shortestSpan() << std::endl;
		std::cout << sp_hto.longestSpan() << std::endl;
	}

}
