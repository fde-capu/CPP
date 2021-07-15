/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PeaceTelepathy.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:52:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 15:06:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEACETELEPATHY_HPP
# define PEACETELEPATHY_HPP

# include "AWeapon.hpp"

class PeaceTelepathy: public AWeapon
{
	public:
		PeaceTelepathy();
		virtual void attack() const;
};

#endif
