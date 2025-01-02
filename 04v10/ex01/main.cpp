/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:34:53 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 19:00:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void shout(std::string str)
{
	std::cout << str << std::endl;
}

int main()
{
//	int n = 5;
//	Animal* pets[n];
//	for (int i = 0; i < n; i++)
//		pets[i] = i % 2 ? \
//			static_cast<Animal*>(new Dog()) : \
//			static_cast<Animal*>(new Cat());
//	for (int i = 0; i < n; i++)
//		delete(pets[i]);	

	Cat kitty;
	kitty.show_brain();
	Cat kat = kitty;
	kat.show_brain();
	return 0;
}
