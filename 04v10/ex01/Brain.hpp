/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:30:31 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 17:07:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		static const int brain_size = 5;
		static const int idea_size = 4;
		std::string ideas[brain_size];
	public:
		Brain(void);
		Brain(Brain const & src);
		Brain &	operator= (Brain const & rhs);
		~Brain(void);
		void show_brain();
};

#endif
