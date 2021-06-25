/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 07:20:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/27 15:03:17 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include "Zombie.hpp"

class	ZombieHorde
{
	private:
		static int _n;
	public:
		Zombie *	z;
		ZombieHorde(int n);
		~ZombieHorde(void);
		void announce(void);
};

#endif
