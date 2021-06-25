/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:25:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/22 17:59:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <string>
# include "Zombie.hpp"

class	ZombieEvent
{
	private:
		std::string	_type;
	public:
		void	setZombieType(std::string type);
		Zombie*	newZombie(std::string name);
		ZombieEvent(void);
};

#endif
