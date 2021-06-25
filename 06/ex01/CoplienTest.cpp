/* ******************************************* */
/*                                             */
/*                     |||:|:|:|||:||||::|:|:: */
/* CoplienTest.cpp     |::|||:::|:||:|:::||:|| */
/*                     ::||::::|::::::||||||:| */
/*                                             */
/*                                             */
/* C20210619183434 |:|::|                      */
/* U20210619194142 |||:|:                      */
/*                                             */
/* ******************************************* */

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
