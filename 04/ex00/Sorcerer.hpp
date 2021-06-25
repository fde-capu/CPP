/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{
	private:
		Sorcerer(void);
	public:
		std::string	name;
		std::string title;
		Sorcerer(std::string u_name, std::string u_title);
		Sorcerer(Sorcerer const & src);
		Sorcerer &	operator = (Sorcerer const & rhs);
		~Sorcerer(void);
		void polymorph(Victim const & victim) const;
};

std::ostream &	operator << (std::ostream & o, Sorcerer const & i);

#endif
