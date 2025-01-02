/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:43 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 16:46:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

void shout(std::string);

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(std::string);
		virtual void makeSound() const;
		std::string getType() const;
};

class Cat : virtual public Animal
{
	public:
		Cat(): Animal("Cat") {};
		void makeSound() const;
};

class Dog : virtual public Animal
{
	public:
		Dog(): Animal("Dog") {};
		void makeSound() const;
};

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(std::string);
		void makeSound() const;
		std::string getType() const;
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(): WrongAnimal("WrongCat") {};
		void makeSound() const;
};

#endif
