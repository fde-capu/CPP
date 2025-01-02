/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:34:53 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 16:45:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void shout(std::string str)
{
	std::cout << str << std::endl;
}

int main()
{
	Animal animal;
	Dog dog;
	Cat cat;

	shout("1");
	animal.makeSound();
	shout("2");
	dog.makeSound();
	shout("3");
	cat.makeSound();

	// subject.pdf:
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " <- j->getType(): Dog" << std::endl;
	std::cout << i->getType() << " <- i->getType(): Cat" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound(); // Nothing.
	// END subject.pdf
	delete meta;
	delete j;
	delete i;

	const WrongAnimal* w_i = new WrongCat();
	std::cout << w_i->getType() << " <- w_i->getType(): WrongCat" << std::endl;
	std::cout << "You're ";
	w_i->makeSound(); //will output the cat sound!
	delete w_i;

	return 0;
}
