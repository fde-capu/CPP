/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:01:05 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/26 16:59:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdio>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	argv += 1;
	while (*argv)
	{
		std::string str(*argv);
		i = 0;
		while (str[i])
			putchar(toupper(str[i++]));
		argv += 1;
	}
	putchar('\n');
	return 0;
}
