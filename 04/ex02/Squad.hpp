/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include <iostream>

class Squad: public ISquad
{
	private:
		int n_units;
		ISpaceMarine ** unit;
		void del_units();
	public:
		Squad(void);
		Squad(Squad const & src);
		Squad & operator = (Squad const & rhs);
		virtual ~Squad(void);
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
};

#endif
