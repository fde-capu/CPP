/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:49 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 09:59:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class Enemy
{
	protected:
		int			hp;
		std::string	type;
	private:
		Enemy(void);
	public:
		virtual ~Enemy(void);
		Enemy(Enemy const & src);
		Enemy & operator= (Enemy const & rhs);
		Enemy(int hp, std::string const & type);
		std::string getType(void) const;
		int getHP(void) const;
		virtual void takeDamage(int);
};

std::ostream & operator<< (std::ostream & o, Enemy const & i);

#endif
