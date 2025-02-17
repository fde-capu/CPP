/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 09:16:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
	private:
		Victim(void) {};
	public:
		std::string name; // Public for demo purposes.
		Victim(std::string u_name);
		Victim(Victim const & src);
		Victim & operator= (Victim const & rhs);
		virtual ~Victim(void);
		virtual void getPolymorphed(void) const;
};

std::ostream & operator<< (std::ostream & o, Victim const & i);

#endif
