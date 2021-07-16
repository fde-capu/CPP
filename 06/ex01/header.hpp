/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:34:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/16 11:34:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP
# include "Data.hpp"

void hex_dump(const s_block &block_as_struct);
void plot(s_block *block_as_struct, std::string title);
void plot(void *block_as_void, std::string title);
void plot(Data *block_as_data, std::string title);
void plot(Data &block_as_data, std::string title);

#endif
