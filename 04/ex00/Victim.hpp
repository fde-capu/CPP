/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
	public:
		Victim(void);
		std::string name;
		Victim(std::string u_name);
		Victim(Victim const & src);
		Victim &	operator = (Victim const & rhs);
		~Victim(void);
		virtual void getPolymorphed(void) const;
};

std::ostream &	operator << (std::ostream & o, Victim const & i);

#endif
