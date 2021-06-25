/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 08:20:41 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/27 08:35:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP
# include <iostream>

std::string	format_search(char *param);
int			prompt_str(const char *txt, std::string *com);
int			ft_isnumber(const char *str);
int			prompt_range(const char *txt, int *num, int min, int max);
std::string	crappy_itos_0to7(int i);

#endif
