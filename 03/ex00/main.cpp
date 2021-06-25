/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:59:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap fr4g_tp("Claptrap");
	std::string victim("a guy");

	{
		std::cout << std::endl << ":: Canonical demo ::" << std::endl << std::endl;
		std::cout << fr4g_tp << std::endl;
		FragTrap copy_fr4g_tp = fr4g_tp;
		std::cout << copy_fr4g_tp << std::endl;
	}

	std::cout << std::endl << ":: Aaaand... Open! ::" << std::endl << std::endl;
	fr4g_tp.rangedAttack(victim);
	std::cout << fr4g_tp << std::endl;
	fr4g_tp.meleeAttack(victim);
	std::cout << fr4g_tp << std::endl;
	fr4g_tp.takeDamage(42);
	std::cout << fr4g_tp << std::endl;
	fr4g_tp.beRepaired(21);
	std::cout << fr4g_tp << std::endl;
	fr4g_tp.vaulhunter_dot_exe(victim);

	std::cout << std::endl << ":: Now, failing tests :: " << std::endl << std::endl;
	std::cout << "After repair, hit_points and energy_points cannot exceed their maximum:" << std::endl;
	fr4g_tp.beRepaired(41);
	std::cout << fr4g_tp << std::endl;
	std::cout << "After some attacks, will fail hit_points short:" << std::endl;
	fr4g_tp.rangedAttack(victim);
	fr4g_tp.meleeAttack(victim);
	fr4g_tp.rangedAttack(victim);
	fr4g_tp.rangedAttack(victim);
	std::cout << fr4g_tp << std::endl;
	fr4g_tp.rangedAttack(victim);
	fr4g_tp.meleeAttack(victim);
	std::cout << std::endl << "After taking damage and/or using vaulhunter.exe, energy shortage will prevent vaulhunter.exe:" << std::endl;
	fr4g_tp.takeDamage(42);
	fr4g_tp.vaulhunter_dot_exe(victim);
	fr4g_tp.takeDamage(42);
	std::cout << fr4g_tp << std::endl;
	fr4g_tp.vaulhunter_dot_exe(victim);
	return 0;
}
