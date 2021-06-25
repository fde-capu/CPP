/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpp.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:39:11 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/27 10:17:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CPP_HPP
# define FT_CPP_HPP

#include <string>

int			ft_isnumber(const char *str);
int			prompt_str(const char *txt, std::string *com);
std::string	ft_toUpper(std::string in);
int			file_exists(char * file);
void		log(const char * msg);
int			log_ret(const char * msg, int ret_val);

#endif
