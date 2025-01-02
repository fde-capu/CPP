/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:34:21 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 16:11:29 by fde-capu         ###   ########.fr       */
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

void WrongCat::makeSound() const
{ shout("MOWHUWHUWO!!!"); }

WrongAnimal::WrongAnimal(void)
{ shout("WrongAnimal::WrongAnimal(void)"); }

WrongAnimal::~WrongAnimal(void)
{ shout("WrongAnimal::~WrongAnimal(void)"); }

WrongAnimal::WrongAnimal(std::string name): type(name)
{ shout("WrongAnimal::WrongAnimal(std::string name): type(name)"); }

void WrongAnimal::makeSound() const
{ shout("Just an animal."); }

std::string WrongAnimal::getType() const
{ return type; }
