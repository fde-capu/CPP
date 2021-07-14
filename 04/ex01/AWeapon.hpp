/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 09:58:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
	protected:
		std::string	name;
		int			apcost;
		int			damage;
	private:
		AWeapon(void);
	public:
		virtual ~AWeapon(void);
		AWeapon(AWeapon const & src);
		AWeapon & operator= (AWeapon const & rhs);
		AWeapon(std::string const & name, int apcost, int damage);
		std::string getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;
		virtual void attack(void) const = 0;
};

std::ostream & operator<< (std::ostream & o, AWeapon const & i);

#endif
