/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LooserStigma.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:11:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 16:45:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOSERSTIGMA_HPP
# define LOSERSTIGMA_HPP

# include "AWeapon.hpp"

class LooserStigma: public AWeapon
{
	public:
		LooserStigma();
		virtual void attack() const;
};

#endif
