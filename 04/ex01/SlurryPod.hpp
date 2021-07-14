/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SlurryPod.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:40:27 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 15:43:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLURRYPOD_HPP
# define SLURRYPOD_HPP

# include "Enemy.hpp"

class SlurryPod: public Enemy
{
	public:
		SlurryPod(void);
		virtual ~SlurryPod(void);
};

#endif
