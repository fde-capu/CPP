/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>

int	main(void)
{
	{
		std::cout << std::endl << "FRAGTRAP SECTION" << std::endl;
		FragTrap fr4g_tp("FragTrappy");
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
	}{
		std::cout << std::endl << "SCAVTRAP SECTION" << std::endl;
		ScavTrap sc4v_tp("Scavtrappy");
		std::string victim("another guy");
		{
			std::cout << std::endl << ":: Canonical demo ::" << std::endl << std::endl;
			std::cout << sc4v_tp << std::endl;
			ScavTrap copy_sc4v_tp = sc4v_tp;
			std::cout << copy_sc4v_tp << std::endl;
		}
		std::cout << std::endl << ":: Aaaand... Open! ::" << std::endl << std::endl;
		sc4v_tp.rangedAttack(victim);
		std::cout << sc4v_tp << std::endl;
		sc4v_tp.meleeAttack(victim);
		std::cout << sc4v_tp << std::endl;
		sc4v_tp.takeDamage(42);
		std::cout << sc4v_tp << std::endl;
		sc4v_tp.beRepaired(21);
		std::cout << sc4v_tp << std::endl;
		sc4v_tp.challengeNewcomer(victim);

		std::cout << std::endl << ":: Now, failing tests :: " << std::endl << std::endl;
		std::cout << "After repair, hit_points and energy_points cannot exceed their maximum:" << std::endl;
		sc4v_tp.beRepaired(41);
		std::cout << sc4v_tp << std::endl;
		std::cout << "After some attacks, will fail hit_points short:" << std::endl;
		sc4v_tp.rangedAttack(victim);
		sc4v_tp.meleeAttack(victim);
		sc4v_tp.rangedAttack(victim);
		sc4v_tp.rangedAttack(victim);
		sc4v_tp.rangedAttack(victim);
		sc4v_tp.rangedAttack(victim);
		std::cout << sc4v_tp << std::endl;
		sc4v_tp.rangedAttack(victim);
		sc4v_tp.meleeAttack(victim);
		std::cout << std::endl << "To challenge a newcomer is not mentioned to have cost:" << std::endl;
		sc4v_tp.takeDamage(42);
		sc4v_tp.challengeNewcomer(victim);
		sc4v_tp.takeDamage(63);
		std::cout << sc4v_tp << std::endl;
		sc4v_tp.challengeNewcomer(victim);
	}
}
