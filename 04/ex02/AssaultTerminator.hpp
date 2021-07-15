/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 07:49:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include "ISpaceMarine.hpp"
# include <iostream>

class AssaultTerminator: public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const & src);
		AssaultTerminator & operator= (AssaultTerminator const & rhs);
		virtual ~AssaultTerminator(void);
		virtual AssaultTerminator* clone() const;
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
};

#endif
