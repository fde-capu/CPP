/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThirstyVamper.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:40:24 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 15:44:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THIRSTYVAMPER_HPP
# define THIRSTYVAMPER_HPP

# include "Enemy.hpp"

class ThirstyVamper: public Enemy
{
	public:
		ThirstyVamper(void);
		virtual ~ThirstyVamper(void);
};

#endif
