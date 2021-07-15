/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HypnoGem.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:46:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 10:48:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HYPNOGEM_HPP
# define HYPNOGEM_HPP
# include "AMateria.hpp"

class HypnoGem: public AMateria
{
	public:
		HypnoGem(void);
		virtual HypnoGem * clone () const;
		virtual void use(ICharacter& target);
};

#endif
