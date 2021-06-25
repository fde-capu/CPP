/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Crap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:40:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/27 08:23:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRAP_HPP
# define CRAP_HPP
# include "header.hpp"

# define BOOK_LIMIT		8
# define ENTRY_LIMIT	24

class	Crap {
	public:
		char	first_name[ENTRY_LIMIT + 1];
		char	last_name[ENTRY_LIMIT + 1];
		char	nickname[ENTRY_LIMIT + 1];
		char	login[ENTRY_LIMIT + 1];
		char	postal_address[ENTRY_LIMIT + 1];
		char	email_address[ENTRY_LIMIT + 1];
		char	phone_number[ENTRY_LIMIT + 1];
		char	birthday_date[ENTRY_LIMIT + 1];
		char	favorite_meal[ENTRY_LIMIT + 1];
		char	underwear_color[ENTRY_LIMIT + 1];
		char	darkest_secret[ENTRY_LIMIT + 1];
				Crap(void);
		void	digest(int idx);
		void	poop(void);
};

#endif
