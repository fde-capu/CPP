/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DealZap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:03:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 15:06:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEALZAP_HPP
# define DEALZAP_HPP

# include "AWeapon.hpp"

class DealZap: public AWeapon
{
	public:
		DealZap();
		virtual void attack() const;
};

#endif
