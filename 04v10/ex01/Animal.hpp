/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:43 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 19:04:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

void shout(std::string);

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(std::string);
		Animal(Animal&);
		virtual Animal& operator= (Animal& rhs);
		virtual void makeSound() const;
		std::string getType() const;
};

class Cat : virtual public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		~Cat();
		virtual Cat& operator= (Cat& rhs);
		virtual void makeSound() const;
		void show_brain() const;
};

class Dog : virtual public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		~Dog();
		virtual Dog& operator= (Dog& rhs);
		virtual void makeSound() const;
		void show_brain() const;
};

#endif
