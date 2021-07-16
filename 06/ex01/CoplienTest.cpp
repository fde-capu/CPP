/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoplienTest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:34:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/16 11:34:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CoplienTest.hpp"

CoplienTest::CoplienTest(void)
{
	std::cout << "CoplienTest::CoplientTest(void)" << std::endl;
	return ;
}

CoplienTest::CoplienTest(CoplienTest const & src)
{
	std::cout << "CoplienTest::CoplienTest(CoplienTest const & src)" << std::endl;
	*this = src;
	return ;
}

CoplienTest & CoplienTest::operator = (CoplienTest const & rhs)
{
	std::cout << "CoplienTest & CoplienTest::operator = (CoplienTest const & rhs)" << std::endl;
	if (this != &rhs)
	{
//		this->member = rhs.getMember();
	}
	return *this;
}

CoplienTest::~CoplienTest(void)
{
	std::cout << "CoplienTest::~CoplienTest(void)" << std::endl;
	return ;
}
