/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:34:21 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 19:06:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{ shout("Animal::Animal(void)"); }

Animal::~Animal(void)
{ shout("Animal::~Animal(void)"); }

Animal::Animal(std::string name): type(name)
{ shout("Animal::Animal(std::string name): type(name)"); }

void Animal::makeSound() const
{ shout("Just an animal."); }

std::string Animal::getType() const
{ return type; }

void Dog::makeSound() const
{ shout("Barf!!"); }

void Cat::makeSound() const
{ shout("Meow..."); }

Dog::Dog(): Animal("Dog")
{
	shout("Dog created.");
	brain = new Brain();
}

Cat::Cat(): Animal("Cat")
{
	shout("Cat created.");
	brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	shout("Dog dead.");
}

Cat::~Cat()
{
	delete brain;
	shout("Cat dead.");
}

void Dog::show_brain() const
{ this->brain->show_brain(); }

void Cat::show_brain() const
{ this->brain->show_brain(); }

Animal::Animal(Animal& rhs)
{
	*this = rhs;
}

Animal& Animal::operator= (Animal& rhs)
{
	shout("Animal::operator=");
	if (this == &rhs)
		return *this;
	return *this;
}

Cat& Cat::operator= (Cat& rhs)
{
	shout("Cat::operator=");
	if (this == &rhs)
		return *this;
		brain = new Brain();
//	*brain = *rhs.brain;
	return *this;
}

Dog& Dog::operator= (Dog& rhs)
{
	if (this == &rhs)
		return *this;
//	*brain = Brain(*rhs.brain);
brain = new Brain();
	return *this;
}
